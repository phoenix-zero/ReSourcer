#include "parser.hpp"

int main(int argc, char** argv)
{
    auto [inputFile,outputFile] = optionParser(argc, argv);
    fileParser(inputFile,outputFile);
    return 0;
}
