/*
 You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

 The area of an island is the number of cells with a value 1 in the island.

 Return the maximum area of an island in grid. If there is no island, return 0.
 */
#include <iostream>
#include <vector>
using namespace std;

class archipelago {
private:
    void area(vector<vector<int>>& image, int sr, int sc, int newColor, int & counter) {
        int color_of_current_element = image[sr][sc];
        
        image[sr][sc] = image[sr][sc]+1;
        
        if ( sr + 1 < image.size() ) {
            if ( image[sr + 1][sc] == color_of_current_element ){
                area(image, sr + 1, sc, newColor, counter);
                counter ++;
            }
        }
        if ( sr - 1 >= 0 ) {
            if ( image[sr - 1][sc] == color_of_current_element ) {
                area(image, sr - 1, sc, newColor, counter);
                counter ++;
            }
        }
        if ( sc + 1 < image[0].size() ) {
            if ( image[sr][sc + 1] == color_of_current_element ) {
                area(image, sr, sc + 1, newColor, counter);
                counter ++;
            }
        }
        if ( sc - 1 >= 0 ) {
            if ( image[sr][sc - 1] == color_of_current_element ) {
                area(image, sr, sc - 1, newColor, counter);
                counter ++;
            }
        }
        
        image[sr][sc] = newColor;
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int counter = 0;
        int largest_area = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if ( grid[i][j] == 1) {
                    counter = 1;
                    area(grid, i, j, 3, counter);
                }
                if (counter > largest_area) largest_area = counter;
            }
        }
        return largest_area;
    }
};



int main() {
    
    archipelago Island;
    
    vector<vector<int>> M =
    {
        {0,0,0,0,0,1,1,1,0,0,0},
    };
    /*
    {
        {0,0,0,1,1},
        {0,0,0,1,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    */
    //Show archipelageo
    
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n" << "Largest area  = " <<Island.maxAreaOfIsland(M);
    
    cout << "\n\n";
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
