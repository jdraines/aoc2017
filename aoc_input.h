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
    std::string getInput(std::string path)
    {
        std::string line;
        std::string input_str = "";
        std::ifstream input(path, std::ios::in);

        if (!input)
        {
            std::cout << "Unable to open input." << std::endl;
            exit(1);
        }

        while (getline(input, line))
        {
            input_str += line;
            input_str += "\n";
        }
        
        input.close();

        return input_str;
    }

    std::vector<std::string> delimSplit(std::string input, char delim)
    {
        std::vector<std::string> inputs;
        std::string one = "";
        
        for (auto ch : input)
        {
            if (ch == delim)
            {
                inputs.push_back(one);
                one = "";
            }
            else
            {
                one += ch;
            }
        }

        if (one.size() > 0)
        {
            inputs.push_back(one);
        }

        return inputs;
    }

    std::vector<int> vecString2vecInt(std::vector<std::string> vecStr)
    {
        // In which each string element of the vector is an integer

        std::vector<int> vecInt;

        for (auto str : vecStr)
        {
            vecInt.push_back(std::stoi(str));
        }
        return vecInt;
    }

}

#endif /* AOC_INPUT_H */