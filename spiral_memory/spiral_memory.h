//spiral_memory.h
#ifndef AOC_SPIRAL_MEM_H
#define AOC_SPIRAL_MEM_H

#include <vector>
#include <string>

namespace aoc_spiral_mem
{
    class SpiralMemory 
    {
    public:
        SpiralMemory(long);
        SpiralMemory(long, std::string);
        long access_steps(long);
        long size();
        long value_at_index(long);
        long value_at_coordinates(std::vector<long>);
        void setValues(std::vector<long>);
        std::vector<std::vector<long>> coordinates();
    
    private:
        long size_;
        std::vector<long> values_;
        void init_values();
        long init_test_values(long);
        std::vector<std::vector<long>> coordinates_;
        std::vector<std::vector<long>> generateCoordinates(long);
        std::vector<std::vector<long>> dBorderCoordinates(long, std::vector<long>);
        long dBordersize(long);
        long dGridSize(long);
        bool coordinateExists(std::vector<long>);
    };
}



#endif /* AOC_SPIRAL_MEM_H */