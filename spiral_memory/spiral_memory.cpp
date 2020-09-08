#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

#include "spiral_memory.h"

using namespace std;
using std::vector;
using std::string;

namespace aoc_spiral_mem
{

    // Public members
    SpiralMemory::SpiralMemory(long size)
    {
        init_values();
    }

    SpiralMemory::SpiralMemory(long size, string values_init): 
        size_(size), 
        coordinates_(SpiralMemory::generateCoordinates(size)) 
    {
        long i;

        // initialize values
        if(values_init=="test")
        {
            init_values();
            i = init_test_values(size_);
            cout << values_[i] << endl;
        }
        else
        {
            init_values();
        }
        
    }

    vector<vector<long>> SpiralMemory::coordinates()
    {
        return coordinates_;
    }


    long SpiralMemory::access_steps(long memory_index)
        {
            return (abs(coordinates_[memory_index-1][0]) + abs(coordinates_[memory_index-1][1]));
        }


    long SpiralMemory::size() { return size_; }


    long SpiralMemory::value_at_index(long index)
    {
        return values_[index];
    }


    long SpiralMemory::value_at_coordinates(vector<long> coord)
    {
        long error = -1;
        long i = 0;

        for (auto mem_coord : coordinates_)
        {
            if (coord == mem_coord) { return values_[i]; }
            i++;
        }
        return error;
    }


    void SpiralMemory::setValues(vector<long> values)
    {
        values_ = values;
    }


    // Private members


    void SpiralMemory::init_values()
    {

        values_ = vector<long>(coordinates_.size(), 0);
    }

    long SpiralMemory::init_test_values(long breakVal)
    {
        values_[0] = 1;

        vector<vector<long>>::size_type i;
        long x = 0;
        long y = 0;
        vector<long> temp_coord = {0,0};
        vector<vector<long>> _border_search_steps = {
            {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0, -1}, {1, -1}
        };
        long val;

        for (i=1; i < coordinates_.size(); i++)
        {
            val = 0;
            x = coordinates_[i][0];
            y = coordinates_[i][1];

            for (auto step : _border_search_steps)
            {
                temp_coord = {x + step[0], y + step[1]};
                if (coordinateExists(temp_coord))
                {
                    val += value_at_coordinates(temp_coord);
                }
                
            }

            values_[i] = val;
            if (val > breakVal) { break; }
        }

        return i;
    }

    bool SpiralMemory::coordinateExists(vector<long> coord)
    {
        if(
            std::find(
                coordinates_.begin(), 
                coordinates_.end(), 
                coord) 
            != coordinates_.end()
            ) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }

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
        vector<vector<long>> _direction_modifiers = { {0,1}, {-1,0}, {0,-1}, {1,0} };

        for (auto dir : _direction_modifiers)
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