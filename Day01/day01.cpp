#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;

string getInput()
{
    string line;
    string input_str = "";
    ifstream input("input.txt", ios::in);

    if (!input)
    {
        cout << "Unable to open input." << endl;
        exit(1);
    }

    while (getline(input, line))
    {
        input_str += line;
    }
    
    input.close();

    return input_str;

}


int sumConsecutives(string input)
{
    int running_sum = 0;
    int i = 0;
    auto len = input.size();
    char first = input[0];

    for (auto ch : input)
    {
        
        if (i != len-1)
        {
            if (ch == input[i+1])
            {
                running_sum += atoi(&ch);
            }
        }

        else 
        {
            if (ch == first)
            {
                running_sum += atoi(&ch);
            }
        }
        
        i++;
    }
    return running_sum;
}


int main() 
{
    string input = getInput();
    cout << sumConsecutives(input) << endl;
}

