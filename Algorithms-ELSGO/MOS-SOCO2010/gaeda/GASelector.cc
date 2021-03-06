// $Header: /nfs/dsi/cvs/galib/ga/GASelector.C,v 1.1.1.1 1999/11/11 18:56:03 mbwall Exp $
/* ----------------------------------------------------------------------------
  selector.C
  mbwall 10aug94
  Copyright (c) 1995 Massachusetts Institute of Technology
                     all rights reserved

 DESCRIPTION:
  This file defines the built-in selection objects for GAlib.
---------------------------------------------------------------------------- */

#include <sstream>

#include "GASelector.h"

#include "gaconfig.h"
#include "garandom.h"
#include "gaerror.h"
#include "GAPopulation.h"
#include "logger/GALogger.h"
#include "genomes/GAGenome.h"

#if USE_DS_SELECTOR == 1
static void GAQuickSort(unsigned int *, long double *, int, int);
#endif


/* ----------------------------------------------------------------------------
RankSelector
---------------------------------------------------------------------------- */
// Any population may contain more than one individual with the same score.
// This method must be able to return any one of those 'best' individuals, so
// we do a short search here to find out how many of those 'best' there are.
//   This routine assumes that the 'best' individual is that with index 0.  It
// uses either the fitness or objective score to do the ranking, depending on
// which was selected in the selector object.
#if USE_RANK_SELECTOR == 1
GAGenome &
GARankSelector::select() const {
  unsigned i, count=1;

  GAPopulation::SortBasis basis =
    (which == SCALED ? GAPopulation::SCALED : GAPopulation::RAW);
  pop->sort(gaFalse, basis);
  if(which == SCALED){
    for(i=1; i<pop->size() &&
	pop->best(i,basis).fitness() == pop->best(0,basis).fitness(); i++)
      count++;
  }
  else{
    for(i=1; i<pop->size() &&
	pop->best(i,basis).score() == pop->best(0,basis).score(); i++)
      count++;
  }
  return pop->best(GARandomInt(0,count-1),basis);
}
#endif


/* ----------------------------------------------------------------------------
UniformSelector
---------------------------------------------------------------------------- */
// Randomly select an individual from the population.  This selector does not
// care whether it operates on the fitness or objective scores.
#if USE_UNIFORM_SELECTOR == 1
GAGenome&
GAUniformSelector::select() const {
  return pop->individual(GARandomInt(0, pop->size()-1));
}
#endif


/* ----------------------------------------------------------------------------
RouletteWheelSelector
---------------------------------------------------------------------------- */
// This selection routine is straight out of Goldberg's Genetic Algorithms
// book (with the added restriction of not allowing zero scores - Goldberg
// does not address this degenerate case).  We look through the members of the
// population using a weighted roulette wheel.  Likliehood of selection is
// proportionate to the fitness score.
//   This is a binary search method (using cached partial sums).  It assumes
// that the genomes are in order from best (0th) to worst (n-1).
#if USE_ROULETTE_SELECTOR == 1 || USE_TOURNAMENT_SELECTOR == 1
GAGenome &
GARouletteWheelSelector::select() const {
  long double cutoff;
  int    i, upper, lower;

  cutoff = GARandomDouble();
  lower  = 0;
  upper  = pop->size()-1;
  while(upper >= lower){
    i = lower + (upper-lower)/2;
    assert(i >= 0 && i < n);

    if(psum[i] > cutoff) upper = i-1;
    else                 lower = i+1;
  }
  lower = GAMin((int)(pop->size())-1, lower);
  lower = GAMax(0, lower);

  return pop->individual(lower, (which == SCALED ? GAPopulation::SCALED : GAPopulation::RAW));
}


// Update our list of partial sums.  Use the appropriate fitness/objective
// scores as determined by the flag.  The delete/alloc assumes that the pop
// size won't be changing a great deal.
//   Our selector requires that the population is sorted (it uses a binary
// search to go faster) so we force the sort here.
void
GARouletteWheelSelector::update() {
  if ( (int) pop->size() != n) {
    delete [] psum;
    n = pop->size();
    psum = new long double [n];
  }

  int i;
  if (which == GASelectionScheme::RAW) {

    if (pop->max() == pop->min()) {
      for (i=0; i<n; i++) psum[i] = (long double)(i+1)/(long double)n; // equal likelihoods
    }

    else if ((pop->max() > 0 && pop->min() >= 0) || (pop->max() <= 0 && pop->min() < 0)) {
      pop->sort(gaFalse, GAPopulation::RAW);

     if (GAGenome::optCriterion() == GAGenome::MAXIMIZATION) {
        psum[0] = pop->individual(0, GAPopulation::RAW).score();

        for (i=1; i<n; i++) psum[i] = pop->individual(i, GAPopulation::RAW).score() + psum[i-1];
        for (i=0; i<n; i++) psum[i] /= psum[n-1];
      }
      else {
        psum[0] = -pop->individual(0, GAPopulation::RAW).score() + pop->max() + pop->min();

        for (i=1; i<n; i++) psum[i] = -pop->individual(i, GAPopulation::RAW).score() + pop->max() + pop->min() + psum[i-1];
        for (i=0; i<n; i++) psum[i] /= psum[n-1];
      }
    }
    else {
      GAErr(GA_LOC, className(), "update - objective",
      "objective scores are not strictly negative or strictly positive",
      "this selection method cannot be used with these scores");
    }
  }
  else {
    if (pop->fitmax() == pop->fitmin()) {
      for (i=0; i<n; i++)
        psum[i] = (long double)(i+1)/(long double)n; // equal likelihoods
    }
    else if ((pop->fitmax() > 0 && pop->fitmin() >= 0) || (pop->fitmax() <= 0 && pop->fitmin() < 0)) {
      pop->sort(gaFalse, GAPopulation::SCALED);
      if (GAGenome::optCriterion() == GAGenome::MAXIMIZATION) {
        psum[0] = pop->individual(0, GAPopulation::SCALED).fitness();
        for (i=1; i<n; i++)
          psum[i] = pop->individual(i, GAPopulation::SCALED).fitness() + psum[i-1];
        for (i=0; i<n; i++)
          psum[i] /= psum[n-1];
      }
      else {
        psum[0]= -pop->individual(0, GAPopulation::SCALED).fitness() + pop->fitmax() + pop->fitmin();
        for (i=1; i<n; i++)
          psum[i] = -pop->individual(i, GAPopulation::SCALED).fitness() + pop->fitmax() + pop->fitmin() + psum[i-1];
        for (i=0; i<n; i++)
          psum[i] /= psum[n-1];
      }
    }
    else {
      stringstream message; message << "this selection method cannot be used with these scores" << endl;
      message << " The maximum value is " << pop->fitmax() << " and the minimum is " << pop->fitmin();

      GALogger::instance()->appendPopulation("GARouletteWheelSelector error","some scores are negative",*pop);

      GAErr(GA_LOC, className(), "update - fitness",
      "fitness scores are not strictly negative or strictly positive",
      message.str().c_str() );
    }
  }
}

#endif


#if USE_TOURNAMENT_SELECTOR == 1


GATournamentSelector::GATournamentSelector(unsigned size, const GASelectionScheme& selector, int w) :
                                            GASelectionScheme(w),
                                            size_(size),
                                            selector_(selector.clone()) {
  assert(size_ > 1);
}

GATournamentSelector::GATournamentSelector(const GATournamentSelector& orig) {
  copy(orig);
}

GATournamentSelector::~GATournamentSelector() {
  delete selector_;
}

void GATournamentSelector::copy(const GATournamentSelector& orig) {
  GASelectionScheme::copy(orig);
  size_ = orig.size_;
  selector_->copy(* orig.selector_);
}

GATournamentSelector& GATournamentSelector::operator=(const GATournamentSelector& orig)  {
  if(&orig != this) copy(orig); return *this;
}

GASelectionScheme* GATournamentSelector::clone() const {
  return new GATournamentSelector(size_,*selector_,which);
}

void GATournamentSelector::assign(GAPopulation& p){
  pop = &p;
  selector_->assign(p);
}

void GATournamentSelector::update(){
  selector_->update();
}

/**
 * Tournament Selector Pick "size" individuals from the population using the RouletteWheel selection method.
 * Then return the better of the individuals. This is derived from the roulette wheel
 * selector so that we can use its update and select method
 */
GAGenome& GATournamentSelector::select() const {
  GAGenome* picked = & selector_->select();

  for (unsigned i=0; i<size_-1; i++) {
    GAGenome& tmp = selector_->select();

    if (tmp.score() == picked->score() ) {       // Guarantees that we dont select always the same ind when the score is the same
      picked = (GAFlipCoin(0.5)) ? picked : &tmp;
    }
    else if(GAGenome::optCriterion() == GAGenome::MINIMIZATION){
      picked = (tmp.score() < picked->score() ) ? &tmp : picked;
    }
    else{
      picked = (tmp.score() > picked->score() ) ? &tmp : picked;
    }
  }
  return *picked;
}

#endif



/* ----------------------------------------------------------------------------
SRSSelector - stochastic remainder sampling

  The selection happens in two stages.  First we generate an array using the
integer and remainder parts of the expected number of individuals.  Then we
pick an individual from the population by randomly picking from this array.
  This is implemented just as in Goldberg's book.  Not very efficient...  In
Goldberg's implementation he uses a variable called 'nremain' so that multiple
calls to the selection routine can be dependent upon previous calls.  We don't
have that option with this architecture; we would need to make selection an
object coupled closely with the population to make that work.
---------------------------------------------------------------------------- */
#if USE_SRS_SELECTOR == 1
GAGenome &
GASRSSelector::select() const {
  return pop->individual(choices[GARandomInt(0, pop->size()-1)],
			 (which == SCALED ?
			  GAPopulation::SCALED : GAPopulation::RAW));
}

// Make sure we have enough memory to work with.  Set values of choices array
// to appropriate values.

// This is the preselection part.  Figure out how many we should expect of
// each individual.  An individual with e of 4.3 will get 4 places and have a
// 30% chance of a 5th place.

// This implementation only works if fitness scores are strictly positive or
// strictly negative.
void
GASRSSelector::update() {
  if(n != (unsigned int)(pop->size())){
    delete [] fraction;
    delete [] choices;
    n = pop->size();
    fraction = new long double [n];
    choices = new unsigned int [n];
  }

  unsigned int i, ne, k=0;

  if(which == GASelectionScheme::RAW){
    if(pop->ave() == 0 || pop->max() == pop->min()){
      for(i=0; (unsigned int)i<n; i++)
	choices[i] = GARandomInt(0, n-1);
    }
    else if((pop->max() >= 0 && pop->min() >= 0) ||
	    (pop->max() <= 0 && pop->min() <= 0)){
      long double expected;
      for(i=0; i<pop->size(); i++){
   if(GAGenome::optCriterion() == GAGenome::MAXIMIZATION)
	  expected =
	    pop->individual(i, GAPopulation::RAW).score()/pop->ave();
	else
	  expected =
	    (-pop->individual(i, GAPopulation::RAW).score()
	     + pop->max() + pop->min())/pop->ave();
	ne = (int)expected;
	fraction[i] = expected - ne;
	while(ne > 0 && k < n){
	  assert(k >= 0 && k < n);
	  choices[k] = i;
	  k++; ne--;
	}
      }
      i=0;
      while(k < pop->size()){
	if(fraction[i] > 0.0 && GAFlipCoin(fraction[i])){
	  assert(k >= 0 && k < n);
	  assert(i >= 0 && i < n);
	  choices[k] = i;
	  fraction[i] -= 1.0;
	  k++;
	}
	i++;
	if(i >= pop->size()) i=0;
      }
    }
    else {
      GAErr(GA_LOC, className(), "update",
	    "objective scores are not strictly negative or strictly positive",
	    "this selection method cannot be used with these scores");
    }
  }
  else {
    if(pop->fitave() == 0 || pop->fitmax() == pop->fitmin()){
      for(i=0; (unsigned int)i<n; i++)
	choices[i] = GARandomInt(0, n-1);
    }
    else if((pop->fitmax() >= 0 && pop->fitmin() >= 0) ||
	    (pop->fitmax() <= 0 && pop->fitmin() <= 0)){
      long double expected;
      for(i=0; i<pop->size(); i++){
   if(GAGenome::optCriterion() == GAGenome::MAXIMIZATION)
	  expected =
	    pop->individual(i, GAPopulation::SCALED).fitness()/pop->fitave();
	else
	  expected =
	    (-pop->individual(i, GAPopulation::SCALED).fitness()
	     + pop->fitmax() + pop->fitmin()) / pop->fitave();
	ne = (int)expected;
	fraction[i] = expected - ne;
	while(ne > 0 && k < n){
	  assert(k >= 0 && k < n);
	  choices[k] = i;
	  k++; ne--;
	}
      }
      i=0;
      int flag = 1;
      while(k < pop->size() && flag){
	if(i >= pop->size()){
	  i=0;
	  flag = 0;
	}
	if(fraction[i] > 0.0 && GAFlipCoin(fraction[i])){
	  assert(k >= 0 && k < n);
	  assert(i >= 0 && i < n);
	  choices[k] = i;
	  fraction[i] -= 1.0;
	  k++;
	  flag = 1;
	}
	i++;
      }
      if(k < pop->size()){
	for(; k<pop->size(); k++)
	  choices[k] = GARandomInt(0,pop->size()-1);
      }
    }
    else {
      GAErr(GA_LOC, className(), "update",
	    "fitness scores are not strictly negative or strictly positive",
	    "this selection method cannot be used with these scores");
    }
  }
}
#endif


/* ----------------------------------------------------------------------------
DSSelector - deterministic sampling

  This is implemented as described in Goldberg's book.
---------------------------------------------------------------------------- */
#if USE_DS_SELECTOR == 1
GAGenome &
GADSSelector::select() const {
  return pop->individual(choices[GARandomInt(0, pop->size()-1)],
			 (which == SCALED ?
			  GAPopulation::SCALED : GAPopulation::RAW));
}

// Make sure we have enough memory to work with. Then calc the choices array.

// This is the preselection part.  Figure out how many we should expect of
// each individual.  An individual with e of 4.3 will get 4 places, an
// individual with e of 5.9 will get 5 places.  If there are any spaces
// remaining then we fill them with the individuals with highest fractional
// values (don't as *ME* why Goldberg does it this way...)

// This implementation only works if fitness scores are strictly positive or
// strictly negative.
void
GADSSelector::update() {
  if(n != (unsigned int)pop->size()){
    delete [] fraction;
    delete [] choices;
    delete [] idx;
    n = pop->size();
    fraction = new long double [n];
    choices = new unsigned int [n];
    idx = new unsigned int [n];
  }

  unsigned int i,ne,k=0;

  if(which == GASelectionScheme::RAW){
    if(pop->ave() == 0 || pop->max() == pop->min()){
      for(i=0; (unsigned int)i<n; i++)
	choices[i] = GARandomInt(0, n-1);
    }
    else if((pop->max() >= 0 && pop->min() >= 0) ||
	    (pop->max() <= 0 && pop->min() <= 0)){
      long double expected;
      for(i=0; i<pop->size(); i++){
	idx[i] = i;
   if(GAGenome::optCriterion() == GAGenome::MAXIMIZATION)
	  expected =
	    pop->individual(i, GAPopulation::RAW).score()/pop->ave();
	else
	  expected =
	    (-pop->individual(i, GAPopulation::RAW).score()
	     + pop->max() + pop->min())/pop->ave();
	ne = (int)expected;
	fraction[i] = expected - ne;

	while(ne > 0 && k < n){
	  assert(k >= 0 && k < n);
	  choices[k] = i;
	  k++; ne--;
	}
      }

      GAQuickSort(idx, fraction, 0, n-1);
      for(i=pop->size()-1; k<pop->size(); k++, i--)
	choices[k] = idx[i];
    }
    else{
      GAErr(GA_LOC, className(), "update",
	    "objective scores are not strictly negative or strictly positive",
	    "this selection method cannot be used with these scores");
    }
  }
  else{
    if(pop->fitave() == 0 || pop->fitmax() == pop->fitmin()){
      for(i=0; (unsigned int)i<n; i++)
	choices[i] = GARandomInt(0, n-1);
    }
    else if((pop->fitmax() >= 0 && pop->fitmin() >= 0) ||
	    (pop->fitmax() <= 0 && pop->fitmin() <= 0)){
      long double expected;
      for(i=0; i<pop->size(); i++){
	idx[i] = i;
   if(GAGenome::optCriterion() == GAGenome::MAXIMIZATION)
	  expected =
	    pop->individual(i, GAPopulation::SCALED).fitness()/pop->fitave();
	else
	  expected =
	    (-pop->individual(i, GAPopulation::SCALED).fitness()
	     + pop->fitmax() + pop->fitmin()) / pop->fitave();
	ne = (int)expected;
	fraction[i] = expected - ne;

	while(ne > 0 && k < n){
	  assert(k >= 0 && k < n);
	  choices[k] = i;
	  k++; ne--;
	}
      }

      GAQuickSort(idx, fraction, 0, n-1);
      for(i=pop->size()-1; k<pop->size(); k++, i--)
	choices[k] = idx[i];
    }
    else{
      GAErr(GA_LOC, className(), "update",
	    "fitness scores are not strictly negative or strictly positive",
	    "this selection method cannot be used with these scores");
    }
  }
}

static void
GAQuickSort(unsigned int *c, long double *s, int l, int r) {
  int i,j;
  long double v;
  unsigned int tc;
  long double ts;

  if(r > l){
    v = s[r]; i = l-1; j = r;
    for(;;){
      while(s[++i] < v); // might exceed max array limit here
      while(s[--j] > v && j > 0);
      if(i >= j) break;
      tc = c[i]; c[i] = c[j]; c[j] = tc;
      ts = s[i]; s[i] = s[j]; s[j] = ts;
    }
    tc = c[i]; c[i] = c[r]; c[r] = tc;
    ts = s[i]; s[i] = s[r]; s[r] = ts;
    GAQuickSort(c,s,l,i-1);
    GAQuickSort(c,s,i+1,r);
  }
}

#endif
