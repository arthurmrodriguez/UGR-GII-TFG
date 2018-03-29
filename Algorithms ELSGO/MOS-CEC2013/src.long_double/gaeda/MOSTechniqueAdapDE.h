#ifndef MOSTechniqueAdapDE_H
#define MOSTechniqueAdapDE_H

#include "MOSTechniqueDE.h"

class MOSTechniqueAdapDE : public MOSTechniqueDE {
 public:
  GADefineIdentity("MOSTechniqueAdapDE", GAID::TechniqueAdapDE);

  MOSTechniqueAdapDE(techIdType id, std::string description,
                     GAGenome::Initializer init, GAGenome::Evaluator evaluator,
                     encodingType encoding, GAGenome* genomeBase,
                     GAGenome::DECrossover crossover,
                     long double F, long double CR, GASelectionScheme* selector);

  void offspring (GAPopulation* origPop, GAPopulation* destPop, unsigned size, unsigned offset);

  void offspring(MOSGenome& dad, MOSGenome& mom, GAPopulation* origPop, GAPopulation* destPop, unsigned size, unsigned offset);

  unsigned offspring (unsigned maxEvals, unsigned& usedEvals, GAPopulation* pop, GAPopulation* auxPop, bool& converged);

 protected:
  virtual void offspring_internal(MOSGenome& genomeM, MOSGenome& newGenomeM, MOSGenome& genome1M, MOSGenome& genome2M, MOSGenome& genome3M);
  void selfAdjustDEParams(const GAPopulation& pop);

  std::vector<long double> _Fv;
  std::vector<long double> _CRv;
};

#endif
