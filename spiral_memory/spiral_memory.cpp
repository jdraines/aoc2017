#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "spiral_memory.h"

using namespace std;
using std::vector;

namespace aoc_spiral_mem
{

    SpiralMemory::SpiralMemory(long size): size_(size), coordinates_(SpiralMemory::generateCoordinates(size)) {}


    long SpiralMemory::access_steps(long memory_index)
        {
            return (abs(coordinates_[memory_index-1][0]) + abs(coordinates_[memory_index-1][1]));
        }


    long SpiralMemory::size() { return size_; }


    vector<vector<long>> SpiralMemory::generateCoordinates(long size)
    {
        long x = 0;
        long d = 0;
        long bordersize;
        vector<long> start = {0, 0};
        vector<vector<long>> coords;
        vector<vector<long>> coord_range;

        coords.push_back(start);

            while (x < size)
            {
                // Generate coordinates of elements in a square grid in which 
                // elements are added by spiraling outward in a counter-clockwise
                // direction. Do this until the number of elements (x) is greater
                // than or equal to some number (input). Coordinates are generated
                // by generating concentric borders where the border is the border
                // of a grid with sides measuring (2d +1), where d is the count of
                // the borders that have been generated.

                d++;
                coord_range = dBorderCoordinates(d, start);

                for (auto coord : coord_range)
                {
                    coords.push_back(coord);
                }

                bordersize = dBordersize(d);
                x += bordersize;

                start = coords[coords.size()-1];
            }
        return coords;
    }


    vector<vector<long>> SpiralMemory::dBorderCoordinates(long d, vector<long> start)
    {
        // Given an unsigned dimension (d), generate the coordinates of the border
        // elements of a grid with sides of size (2d +1), starting at some coordinate
        // location (start) and moving counterclockwise around the border of the grid.

        vector<vector<long>> coords;
        vector<long> loc;
        long x = start[0] + 1;
        long y = start[1];
        vector<vector<long>> directions = { {0,1}, {-1,0}, {0,-1}, {1,0} };

        for (auto dir : directions)
        {   
            if (dir[0] != 0)
            {
                do
                {   
                    loc = {x,y};
                    coords.push_back(loc);
                    x += dir[0];
                } while (abs(x) < d);
            }
            else
            {
                do
                {
                    loc = {x, y};
                    coords.push_back(loc);
                    y += dir[1];
                } while(abs(y) < d);
            }
            
        }

        // the last loc gets dropped unless we...
        loc = {x, y};
        coords.push_back(loc);

        // sanity check
        if (dBordersize(d) != coords.size())
        {
            cout << "dimensions: " << d << "\n";
            for (auto x : coords)
            {
                cout << "(" <<x[0] << ", " << x[1] << ")\n";
            }
            exit(1);
        }

        return coords;
    }


    long SpiralMemory::dBordersize(long d)
    {
        // Given an unsigned dimension (d) return the number of elements in the
        // border of a square grid with sides of size (2d +1).
        long outer = dGridSize(d);
        long inner = dGridSize(d-1);
        return outer - inner;
    }


    long SpiralMemory::dGridSize(long d)
    {
        // Given an unsigned dimension (d), return the size of a square grid
        // of sides (2d + 1), as if the square's sides were centered on an axis
        // and each side extended from -d to d.
        return ((2*d) + 1) * ((2*d) + 1);
    }

}