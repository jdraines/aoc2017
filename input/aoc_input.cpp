#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;
using std::string;
using std::ifstream;
using std::vector;

namespace aocinput 
{
    string getInput(std::string path)
    {
        string line;
        string input_str = "";
        ifstream input(path, ios::in);

        if (!input)
        {
            cout << "Unable to open input." << endl;
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

    vector<string> delimSplit(string input, char delim)
    {
        vector<string> inputs;
        string one = "";
        
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

    vector<int> vecString2vecInt(vector<string> vecStr)
    {
        // In which each string element of the vector is an integer

        vector<int> vecInt;

        for (auto str : vecStr)
        {
            vecInt.push_back(stoi(str));
        }
        return vecInt;
    }

}