//spiral_memory.h
#ifndef AOC_SPIRAL_MEM_H
#define AOC_SPIRAL_MEM_H

#include <vector>

namespace aoc_spiral_mem
{
    class SpiralMemory 
    {
    public:
        SpiralMemory(long);
        long access_steps(long);
        long size();
    
    private:
        long size_;
        std::vector<std::vector<long>> coordinates_;
        std::vector<std::vector<long>> generateCoordinates(long);
        std::vector<std::vector<long>> dBorderCoordinates(long, std::vector<long>);
        long dBordersize(long);
        long dGridSize(long);
    };
}



#endif /* AOC_SPIRAL_MEM_H */