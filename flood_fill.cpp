/*
 An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

 You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

 To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

 Return the modified image after performing the flood fill.
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color_of_current_element = image[sr][sc];
        
        image[sr][sc] = image[sr][sc]+1;
        
        if ( sr + 1 < image.size() ) {
            if ( image[sr + 1][sc] == color_of_current_element ){
                floodFill(image, sr + 1, sc, newColor);
            }
        }
        if ( sr - 1 >= 0 ) {
            if ( image[sr - 1][sc] == color_of_current_element ) {
                floodFill(image, sr - 1, sc, newColor);
            }
        }
        if ( sc + 1 < image[0].size() ) {
            if ( image[sr][sc + 1] == color_of_current_element ) {
                floodFill(image, sr, sc + 1, newColor);
            }
        }
        if ( sc - 1 >= 0 ) {
            if ( image[sr][sc - 1] == color_of_current_element ) {
                floodFill(image, sr, sc - 1, newColor);
            }
        }
        
        image[sr][sc] = newColor;
        
        return image;
    }
};

int main() {
    vector<vector<int>> M =
    {
        {0,0,0},
        {0,1,1}
    };
    Solution flood;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    flood.floodFill(M, 1, 1, 3);
    cout << "\n";
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
