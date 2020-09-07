#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using std::vector;

int d_grid(int d)
{
    // Given an unsigned dimension (d), return the size of a square grid
    // of sides (2d + 1), as if the square's sides were centered on an axis
    // and each side extended from -d to d.
    return ((2*d) + 1) * ((2*d) + 1);
}

int d_bordersize(int d)
{
    // Given an unsigned dimension (d) return the number of elements in the
    // border of a square grid with sides of size (2d +1).
    int outer = d_grid(d);
    int inner = d_grid(d-1);
    return outer - inner;
}

vector<vector<int>> d_coords(int d, vector<int> start)
{
    // Given an unsigned dimension (d), generate the coordinates of the border
    // elements of a grid with sides of size (2d +1), starting at some coordinate
    // location (start) and moving counterclockwise around the border of the grid.

    vector<vector<int>> coords;
    vector<int> loc;
    int x = start[0] + 1;
    int y = start[1];
    vector<vector<int>> directions = { {0,1}, {-1,0}, {0,-1}, {1,0} };

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
    if (d_bordersize(d) != coords.size())
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

int main()
{
    long input = 277678;
    long x = 0;
    int d = 0;
    int bordersize;
    vector<int> start = {0, 0};
    vector<vector<int>> coords;
    vector<vector<int>> coord_range;

    coords.push_back(start);

        while (x < input)
        {
            // Generate coordinates of elements in a square grid in which 
            // elements are added by spiraling outward in a counter-clockwise
            // direction. Do this until the number of elements (x) is greater
            // than or equal to some number (input). Coordinates are generated
            // by generating concentric borders where the border is the border
            // of a grid with sides measuring (2d +1), where d is the count of
            // the borders that have been generated.

            d++;
            coord_range = d_coords(d, start);

            for (auto coord : coord_range)
            {
                coords.push_back(coord);
            }

            bordersize = d_bordersize(d);
            x += bordersize;

            start = coords[coords.size()-1];
        }
    
    cout << "Distance traveled: " << (abs(coords[input-1][0]) + abs(coords[input-1][1])) << endl;
}