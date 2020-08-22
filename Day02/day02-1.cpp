#include "../aoc_input.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace aocinput;
using namespace std;
using std::string;
using std::vector;

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

long calcAnswer(vector<vector<int>> input)
{
    long answer = 0;
    int min;
    int max;
    int diff;

    for (auto i : input)
    {
        min = *min_element(i.begin(), i.end());
        max = *max_element(i.begin(), i.end());
        diff = max - min;
        answer += diff;
    }

    return answer;
}

int main()
{
    vector<vector<int>> input = formattedInput();
    cout << calcAnswer(input) << endl;
}
