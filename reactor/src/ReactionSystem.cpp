#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

reactor::ReactionSystem::ReactionSystem()
{
  // do nothing
}

reactor::Species & reactor::ReactionSystem::NewSpecies(const std::string &name){
	species.push_back(new Species(name));
	return *species.back();
}

void reactor::ReactionSystem::AddReaction(reactor::Reaction &reaction){
	reactions.push_back(&reaction);
}