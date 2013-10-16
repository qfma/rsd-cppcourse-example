#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

reactor::ReactionSystem::ReactionSystem()
{
  // do nothing
}

reactor::Species & reactor::ReactionSystem::NewSpecies(const std::string &name){
	species.push_back(new Species(name));
	return *species.back();
}

reactor::Reaction & reactor::ReactionSystem::NewReaction(double rate) 
{ 
	reactions.push_back(new Reaction(rate));
	return *reactions.back();
}

