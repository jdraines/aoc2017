#include "aoc_input.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace aocinput;
using namespace std;
using std::string;
using std::vector;
typedef vector<int>::size_type vsize;

vector<vector<int>> formattedInput()
{
    string input = getInput(string("input.txt"));
    vector<int> lineVecInt;
    vector<vector<int>> formatted;
    int num;

    for (auto line : delimSplit(input, '\n'))
    {
        for (auto numstr : delimSplit(line, '\t'))
        {
            num = stoi(numstr);
            lineVecInt.push_back(num);
        }
        formatted.push_back(lineVecInt);
        lineVecInt.clear();
    }
    return formatted;
}

bool isFactor(long long_a, long long_b)
{
    double double_a = static_cast<double>(long_a);
    double double_b = static_cast<double>(long_b);

    return long_a / long_b == double_a / double_b;
}

long calcAnswer(vector<vector<int>> input)
{
    long answer = 0;
    int i;
    int j;
    int dividend;

    for (auto ints : input)
    {
        for  (i = 0; i < ints.size(); i++)
        {
            dividend = ints[i];
            for (j = 0; j < ints.size(); j++)
            {
                if (j!=i)
                {
                    if (isFactor(dividend, ints[j]))
                    {
                        answer += dividend / ints[j];
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> input = formattedInput();
    cout << calcAnswer(input) << endl;
}
