// $Header: /home/cvs/galib/ga/GAPopulation.h,v 1.2 2004/12/28 00:12:11 mwall Exp $
/* ----------------------------------------------------------------------------
  population.h
  mbwall 3aug94
  Copyright (c) 1995 Massachusetts Institute of Technology
                     all rights reserved

 DESCRIPTION:
  The population holds an array of pointers to genomes.  It also keeps
track of the fitness statistics for the genomes in the population.
---------------------------------------------------------------------------- */
#ifndef GAPOPULATION_H
#define GAPOPULATION_H

/* INCLUDES */
#include "gaid.h"
#include "gaconfig.h"
#include "GASelector.h"
#include "GAScaling.h"
#include "GAEvalData.h"
#include "genomes/GAGenome.h"

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif


/* ----------------------------------------------------------------------------
size
  Use the size member function to get and set the size of the population.  The
population allocates space for genomes in chunks, so you can vary the
chunksize as well if you are really tight for space.  The compact member
function will remove all extra pointers.  If you shrink the population to 0
then you cannot use the 'size' method to make the population bigger.  When
resizing to a larger size, we clone randomly individuals from the existing
population.

sort
  The sort member is defined so that it can work on a const population.  It
does not change the logical state of the population, but it does change its
physical state.  We sort from best (0th individual) to worst (n-1).  The sort
figures out whether high is best or low is best.

evaluate
  If you want to force an evaluation, pass gaTrue to the evaluate member
function.  Otherwise the population will use its internal state to determine
whether or not it needs to do the evaluation.

initialize
  This method determines how the population should be initialized.  The
default is to call the initializer for each genome.

statistics
  Update the statistics.  We do this only on-demand so that no unneeded
calculations take place.

diversity
  Like the statistics function, we call this one only on demand.  This member
function can be particularly expensive, especially for large populations.  So
we store the values and update them only as needed.  The population diversity
measure is the average of the individual measures (less the diagonal scores).
---------------------------------------------------------------------------- */
class GAPopulation : public GAID {
	public:
		GADefineIdentity("GAPopulation", GAID::Population);

		typedef void (*Initializer)(GAPopulation &, long double perc);
		typedef void (*Evaluator)(GAPopulation &);

		static void DefaultInitializer(GAPopulation &, long double perc);
		static void DefaultEvaluator(GAPopulation &);

    static void PercInitializer(GAPopulation & p, long double perc);

	public:
		enum SortBasis { RAW, SCALED };
		enum Replacement { BEST = -1, WORST = -2, RANDOM = -3 };

	public:
		GAPopulation();
		GAPopulation(const GAGenome & c, unsigned int psize=1);
		GAPopulation(const GAPopulation & arg);
		GAPopulation & operator=(const GAPopulation & arg){copy(arg); return(*this);}

                GAPopulation(const vector<GAGenome*>& genomes);

                virtual ~GAPopulation();
		virtual GAPopulation * clone() const {return new GAPopulation(*this);}
		virtual void copy(const GAPopulation & arg);

		unsigned int size() const { return n; }
		unsigned int size(unsigned int popsize);
		int chunksize() const { return csz; }
		int chunksize(unsigned int csize) { return csz=csize; }
		int compact();

		void touch()
		{ rsorted=ssorted=selectready=divved=statted=scaled=evaluated=gaFalse; }
		void statistics(GABoolean flag=gaFalse) const;
		void diversity(GABoolean flag=gaFalse) const;
		void scale(GABoolean flag=gaFalse) const;
		void prepselect(GABoolean flag=gaFalse) const;
		void sort(GABoolean flag=gaFalse, SortBasis basis=RAW) const;

		long double sum() const {if(!statted) statistics(); return rawSum;}
		long double ave() const {if(!statted) statistics(); return rawAve;}
		long double var() const {if(!statted) statistics(); return rawVar;}
		long double dev() const {if(!statted) statistics(); return rawDev;}
		long double max() const {if(!statted) statistics(); return rawMax;}
		long double min() const {if(!statted) statistics(); return rawMin;}
		long double div() const {if(!divved)  diversity();  return popDiv;}
		long double div(unsigned int i, unsigned int j) const
		{if(!divved) diversity(); return indDiv[i*n+j];}
		long double fitsum() const {if(!scaled) scale(); return fitSum;}
		long double fitave() const {if(!scaled) scale(); return fitAve;}
		long double fitmax() const {if(!scaled) scale(); return fitMax;}
		long double fitmin() const {if(!scaled) scale(); return fitMin;}
		long double fitvar() const {if(!scaled) scale(); return fitVar;}
		long double fitdev() const {if(!scaled) scale(); return fitDev;}

		// BEGIN: Genealogy
		void computeAge(); // Compute the age of each genome
		// END: Genealogy

		int nevals() const { return neval; }
		void evaluate(GABoolean flag=gaFalse) {
			if(evaluated == gaFalse || flag == gaTrue){
				(*eval)(*this); neval++;
				scaled = statted = divved = rsorted = ssorted = gaFalse;
			}
			evaluated = gaTrue;
		}
		Evaluator evaluator() const {return eval;}
		Evaluator evaluator(Evaluator e)
		{ evaluated = gaFalse; return eval=e; }
		void initialize() { neval = 0; (*init)(*this, initPerc); touch(); }
		Initializer initializer() const {return init;}
		Initializer initializer(Initializer i)
		{ return init=i; }
		GAGenome & select() { if(!selectready) prepselect(); return slct->select(); }
		GASelectionScheme & selector() const { return *slct; }
		GASelectionScheme & selector(const GASelectionScheme&);
		GAScalingScheme & scaling() const {
			GAPopulation* This = (GAPopulation*)this;
			This->scaled=gaFalse;
			return *sclscm;
		}
		GAScalingScheme & scaling(const GAScalingScheme&);

		GAGeneticAlgorithm * geneticAlgorithm() const {return ga;}
		GAGeneticAlgorithm * geneticAlgorithm(GAGeneticAlgorithm&);
		void * userData() const {return ud;}
		void * userData(void * u){return(ud=u);}
		GAEvalData * evalData() const {return evaldata;}
		GAEvalData * evalData(const GAEvalData& o)
		{delete evaldata; evaldata = o.clone(); return evaldata;}

		GAGenome& best(unsigned int i=0, SortBasis basis=RAW) const {
			if(basis == SCALED) scale();
			sort(gaFalse, basis);
			return ((basis == RAW) ? *(rind[i]) : *(sind[i]));
		}
		GAGenome& worst(unsigned int i=0, SortBasis basis=RAW) const {
			if(basis == SCALED) scale();
			sort(gaFalse, basis);
			return ((basis == RAW) ? *(rind[n-1-i]) : *(sind[n-1-i]));
		}
		GAGenome& individual(unsigned int i, SortBasis basis=RAW) const
		{ return ((basis == RAW) ? *(rind[i]) : *(sind[i])); }

		GAGenome * add(GAGenome *);
		GAGenome * add(const GAGenome&);
                void add(const GAGenome& g, unsigned size);
		GAGenome * remove(int which=WORST, SortBasis basis=RAW);
		GAGenome * remove(GAGenome *);
		GAGenome * replace(GAGenome *, int which=RANDOM, SortBasis basis=RAW);
		GAGenome * replace(GAGenome * newgenome, GAGenome * oldgenome);
		void destroy(int w=WORST, SortBasis b=RAW) { delete remove(w,b); }

                GAGenome& medoid() const;
                long double    SumOfDistanceToPop(unsigned int ind_pos) const;
                long double*   genDistsMatrix    (                    ) {diversity(); return indDiv;}
                long double    distAvgPoint      (                    ) const;
                long double    entropy           (                    ) const;
                long double    grefenstetteBias  (                    ) const;
                long double    nativePrcnt       ( unsigned rank      ) const;


    long double initPercentage(long double _initPerc)       {return initPerc = _initPerc;}
    long double initPercentage(                ) const {return initPerc;            }

#ifdef GALIB_USE_STREAMS
		virtual void read(STD_ISTREAM &){}
		virtual void write (STD_OSTREAM & os, SortBasis basis=RAW) const;
                long double avgGenDiv() const ;
#endif


	public:
		unsigned int neval;		// number of evals since initialization
		unsigned int csz;		// how big are chunks we allocate?
		unsigned int n, N;		// how many are in the population, allocated
		GABoolean rsorted;		// are the individuals sorted? (raw)
		GABoolean ssorted;		// are the individuals sorted? (scaled)
		GABoolean scaled;		// has the population been scaled?
		GABoolean statted;		// are the stats valid?
		GABoolean evaluated;		// has the population been evaluated?
		GABoolean divved;		// has the population diversity been measured?
		GABoolean selectready;	// has the selector been updated?
		long double rawSum, rawAve;		// sum, ave of the population's objectives
		long double rawMax, rawMin;		// max, min of the population's objectives
		long double rawVar, rawDev;		// variance, standard deviation
		long double popDiv;			// overall population diversity [0,)
		long double* indDiv;		// table for genome similarities (diversity)
		GAGenome** rind;		// the individuals of the population (raw)
		GAGenome** sind;		// the individuals of the population (scaled)
		long double fitSum, fitAve;		// sum, ave of the population's fitness scores
		long double fitMax, fitMin;		// max, min of the population's fitness scores
		long double fitVar, fitDev;		// variance, standard deviation of fitness
		GAScalingScheme* sclscm;	// scaling method
		GASelectionScheme* slct;	// selection method
		Initializer init;		// initialization method
		Evaluator eval;		// population evaluation method
		void* ud;		        // pointer to user data
		GAGeneticAlgorithm* ga;	// the ga that is using this population
		GAEvalData* evaldata;		// data for evaluator to use (optional)

    long double initPerc;

		int grow(unsigned int);

		//static void quickSortPopRec(SortOrder sort_order, GAGenome** all_inds, int left_pos, int right_pos);
		static void QuickSortAscendingRaw(GAGenome**, int, int);
		static void QuickSortDescendingRaw(GAGenome**, int, int);
		static void QuickSortAscendingScaled(GAGenome**, int, int);
		static void QuickSortDescendingScaled(GAGenome**, int, int);
};



#ifdef GALIB_USE_STREAMS
inline STD_OSTREAM& operator<< (STD_OSTREAM& os, const GAPopulation & arg)
{ arg.write(os); return os; }
inline STD_ISTREAM& operator>> (STD_ISTREAM& is, GAPopulation & arg)
{ arg.read(is); return is; }
#endif

#endif
