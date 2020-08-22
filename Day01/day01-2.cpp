#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;
typedef string::size_type ssize;

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

long halfStep(ssize len, long loc)
{
    long naive = (len / 2) + loc;
    if (naive >= len)
    {
        return naive - len;
    }

    return naive;

}

int sumConsecutives(string input)
{
    int running_sum = 0;
    int i = 0;
    ssize len = input.size();
    char first = input[0];

    for (char ch : input)
    {
        
        if (ch == input[halfStep(len, i)])
        {
            running_sum += atoi(&ch);
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

