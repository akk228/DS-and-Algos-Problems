/*
 You are given an m x n grid where each cell can have one of three values:

 0 representing an empty cell,
 1 representing a fresh orange, or
 2 representing a rotten orange.
 Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

 Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 */
#include <iostream>
#include <vector>
using namespace std;

class Box {
public:
    void orangesRotting(vector<vector<int>>& grid) {
        int length = (int) grid[0].size(), hight = (int) grid.size();
        
        int aux_int = length*hight;
        
        //Horizontal distances
        
        for ( int i = 0; i < hight; i++){
            for ( int j = 0; j < length; j++){
                if ( grid[i][j] != 0 and grid[i][j] != 2 and j == 0 ) grid[i][j] = aux_int;
                // Here, I pick 10 but it doesn't really matter what positive integer to add
                if ( grid[i][j] != 0 and grid[i][j] != 2 and j > 0 and grid[i][j-1] == 0 ) grid[i][j] = aux_int;
                // Here, I pick 10 but it doesn't really matter what positive integer to put
                if ( grid[i][j] != 0 and grid[i][j] != 2 and j > 0 and grid[i][j-1] != 0 ) grid[i][j] = grid[i][j-1] + 1;
            }
            for ( int j = length-1; j >= 0; j--) {
                if ( grid[i][j] != 0 and grid[i][j] != 2 and j < length - 1 and grid[i][j+1] != 0 ) grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
            }
        }
        
        // Vertical distances
        for ( int j = 0; j < length; j++) {
            for ( int i = 0; i < hight; i++) {
                if ( i > 0){
                    if ( grid[i][j] != 0 and grid[i][j] != 2 and grid[i-1][j] != 0 ) grid[i][j] = min(grid[i][j], grid[i-1][j] + 1 );
                }
            }
            for ( int i = hight - 2; i >= 0; i--) {
                if ( grid[i][j] != 0 and grid[i][j] != 2 and grid[i+1][j] != 0 and i < hight - 1  ) grid[i][j] = min(grid[i][j], grid[i+1][j] + 1 );
            }
        }
        
        int counter = length > hight ? length : hight;
        
        while (counter >= 0){
        //Horizontal distances
        
        
        for ( int i = 0; i < hight; i++){
            for ( int j = 0; j < length; j++){
                if ( grid[i][j] != 0 and grid[i][j] != 2 and j > 0 and grid[i][j-1] != 0 ) grid[i][j] = min(grid[i][j],grid[i][j-1] + 1);
            }
            for ( int j = length-2; j >= 0; j--) {
                if ( grid[i][j] != 0 and grid[i][j] != 2 and grid[i][j+1] != 0 ) grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
            }
        }
        
        // Vertical distances
        for ( int j = 0; j < length; j++) {
            for ( int i = 0; i < hight; i++) {
                if ( i > 0){
                    if ( grid[i][j] != 0 and grid[i][j] != 2 and grid[i-1][j] != 0 ) grid[i][j] = min(grid[i][j], grid[i-1][j] + 1 );
                }
            }
            for ( int i = hight - 2; i >= 0; i--) {
                if ( grid[i][j] != 0 and grid[i][j] != 2 and grid[i+1][j] != 0 and i < hight - 1  ) grid[i][j] = min(grid[i][j], grid[i+1][j] + 1 );
            }
        }
           counter--;
        }
        int largest_distance = 0;
        
        for ( int i = 0; i < hight; i++ ) {
            for (int j = 0; j < length; j++) {
                if (grid[i][j] == aux_int) {
                    cout << "There are fresh oranges left!" << endl;
                    return;
                }
                if ( grid[i][j] - 2 > largest_distance ) largest_distance = grid[i][j] - 2;
            }
        }
        cout << "Will rot in " << largest_distance << " min." << endl;
        
    }
};

int main() {
    
    vector<vector<int>> grid =
    {
        {2,0,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,0,1},
        {1,0,1,0,1,0,0,1,0,1},
        {1,0,1,0,1,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    
    Box cart;
    
    cart.orangesRotting(grid);
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j]-2 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
