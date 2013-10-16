#include <string> // use the string capabilities from the standard library
#include <vector>
#include <exception>

#include "Species.h"
#include "Reaction.h"

#ifndef ONCE_REACTIONSYSTEM_H
#define ONCE_REACTIONSYSTEM_H
namespace reactor{

  class ReactionSystem // A "class" is a user defined type with built-in functions
  {   
  public:
    ReactionSystem(); // Declare constructor function.
    void AddSpecies(Species & species);
    const std::vector<Species *> & GetSpecies() const { return species;}

  private:
    std::vector< Species * > species;
  };
}

#endif //ONCE_REACTIONSYSTEM_H
