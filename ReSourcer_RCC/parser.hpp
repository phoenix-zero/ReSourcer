#ifndef PARSER_H
#define PARSER_H
#include <iostream>

std::pair<std::string,std::string> optionParser(int argc, char** argv);
void fileParser(std::string input, std::string output);
#endif
