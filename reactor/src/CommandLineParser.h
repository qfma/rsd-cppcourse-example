#include <iostream>
#include <vector>

#ifndef ONCE_COMMAND_LINE_PARSER
#define ONCE_COMMAND_LINE_PARSER

class CommandLineParser {
public:
	CommandLineParser(int argument_count, const char **command_line_arguments);

	std::vector<double> & GetInitialConditions(){return initial_conditions;}
	std::string & GetReactionSystemFileName(){return reaction_system_file_name;}
private:
	std::string reaction_system_file_name;
	std::vector<double> initial_conditions;
};

#endif