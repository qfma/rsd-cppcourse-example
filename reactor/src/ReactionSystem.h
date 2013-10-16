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

    Reaction & NewReaction(double rate);
    const std::vector<Reaction *> & GetReactions() const {return reactions;}

    Species & NewSpecies(const std::string &name);
    const std::vector<Species *> & GetSpecies() const { return species;}

  private:
    std::vector< Reaction * > reactions;
    std::vector< Species * > species;
  };
}

#endif //ONCE_REACTIONSYSTEM_H
