#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

reactor::ReactionSystem::ReactionSystem()
{
  // do nothing
}

void reactor::ReactionSystem::AddSpecies(reactor::Species &new_species){
	species.push_back(&new_species);
}
