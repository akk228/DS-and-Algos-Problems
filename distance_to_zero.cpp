/*
 Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

 The distance between two adjacent cells is 1.
 */
#include <iostream>
#include <vector>

using namespace std;

class Matrix_Analysis {
public:
    void closest_0 (vector<vector<int>>& mat) {
        int length = (int) mat[0].size(), hight = (int) mat.size();
        //Horizontal distances
        for (int row = 0; row < hight; row++) {
            for (int col = 0; col < length; col++) {
                if ( mat[row][col] != 0 and col == 0 ) mat[row][col] = length+hight;
                if ( ( mat[row][col] != 0 ) and ( col > 0 ) ) mat[row][col] = mat[row][col-1]  + 1;
            }
            for (int col = length - 1; col >= 0; col--) {
                if ( ( mat[row][col] != 0 ) and ( col < length - 1 ) ) mat[row][col] = min( mat[row][col], mat[row][col+1]  + 1);
            }
        }
        
        //Vertical distances
        for (int col = 0; col < length; col++) {
            for (int row = 0; row < hight; row++) {
                if ( ( mat[row][col] != 0 ) and ( row > 0 ) ) mat[row][col] = min(mat[row][col], mat[row-1][col] + 1);
            }
            for (int row = hight - 1; row >= 0; row--) {
                if ( ( mat[row][col] != 0 ) and ( row < hight - 1 ) ) mat[row][col] = min( mat[row][col], mat[row+1][col]  + 1);
            }
        }
        
    }
};


int main() {
    
    vector<vector<int>> M =
       
    {
        {0,1,0},
        {0,1,0},
        {0,1,0},
        {0,1,0},
        {0,1,0]
    };
    
    Matrix_Analysis check;
    
    check.closest_0(M);
    
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
