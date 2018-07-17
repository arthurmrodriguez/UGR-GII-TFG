#include "MOSQualityFunction.h"

#include "GAPopulation.h"
#include "MOSTechnique.h"
#include "MOSTechniqueSet.h"
#include "extras/distaux.h"
#include "genomes/MOSGenome.h"
   #include <iomanip>
/**
 * Quality function: Average Fitness
 */
long double AverageFitnessQuality::averageFitness(const GAPopulation& pop, techIdType id, unsigned newInds) {

  unsigned nIndividualVector = 0;
  long double   acumQualityVector = 0.0;

  // Analize the population to retrieve the total number of individuals
  // generated by the given technique and their scores
  for (unsigned i = 0; i < newInds; i++) {
    MOSGenome& g = dynamic_cast<MOSGenome&> (pop.individual(i));
    if (g.getTechniqueId() == id) {
      nIndividualVector += 1;
      acumQualityVector += g.score();
    }
  }

  // Compute the average fitness of the given technique
  if (nIndividualVector > 0)
    return acumQualityVector / nIndividualVector;
  else
    return 0;

}


/**
 * Quality function: Average Fitness Increment
 */
long double AverageFitnessIncrementQuality::averageFitnessIncrement(const GAPopulation& pop, techIdType id, unsigned newInds) {

  unsigned nIndividualVector = 0;
  long double   acumQualityVector = 0.0;

  // Analize population to retrieve the total number of individuals
  // generated by the given technique and their fitness increments
  for (unsigned i = 0; i < pop.size(); i++) {
    MOSGenome& g = dynamic_cast<MOSGenome&> (pop.individual(i));
    if (g.getTechniqueId() == id && g.mustComputeQuality()) {
      nIndividualVector += 1;
      acumQualityVector += g.getFitnessIncrement();
      g.mustComputeQuality(false);
    }
  }

  // Compute the average fitness increment of the given technique
  if (nIndividualVector > 0) {
    return acumQualityVector / newInds;
  }
  else
    return 0;

}


/**
 * Quality function: Average Diversity
 */
long double AverageDiversityQuality::averageDiversity(const GAPopulation& pop, techIdType id, unsigned newInds) {

  vector<GAGenome*> subpop;

  for (unsigned i = 0; i < newInds; i++) {
    MOSGenome& ind = dynamic_cast<MOSGenome&>(pop.individual(i));
    if (ind.getTechniqueId() == id)
      subpop.push_back(&ind);
  }

  return computeDiversityAvg(subpop);

}
