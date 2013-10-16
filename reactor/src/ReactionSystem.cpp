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

reactor::ReactionSystem::~ReactionSystem(){
	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		delete *each_species;
	}
	for (std::vector< Reaction *>::iterator each_reaction=reactions.begin();each_reaction!=reactions.end();each_reaction++)
	{
		delete *each_reaction;
	}
}