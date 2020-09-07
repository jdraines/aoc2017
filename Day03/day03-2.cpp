#include <iostream>
#include <vector>
#include <cmath>
#include "spiral_memory.h"
// #include "boost/range/combine.hpp"

using namespace std;
using std::vector;
using namespace aoc_spiral_mem;
using aoc_spiral_mem::SpiralMemory;

int main()
{
    // Run part 1 using the SpiralMemory class

    long input = 277678;

    SpiralMemory mem = SpiralMemory(input);

    cout << mem.access_steps(input);
}