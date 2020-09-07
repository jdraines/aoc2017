// aoc_input.h
#ifndef AOC_INPUT_H
#define AOC_INPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

namespace aocinput 
{
    std::string getInput(std::string path);

    std::vector<std::string> delimSplit(std::string input, char delim);

    std::vector<int> vecString2vecInt(std::vector<std::string> vecStr);
    
}

#endif /* AOC_INPUT_H */