#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> square;
        int first = 0, last = nums.size() - 1;
        
        while ( first <= last ){
            if ( nums.at(last)*nums.at(last) >= nums.at(first)*nums.at(first) ) {
                square.push_back( nums[last]*nums[last] );
                last--;
            }else{
                square.push_back( nums[first]*nums[first] );
                first++;
            }
        }
        for (int i = 0; i<nums.size(); i++){
            nums[i] = square[nums.size()-1-i];
        }
        return nums;
    }
};

int main()
{
    vector<int> a ={-7,-3,0,2,3,11};
    Solution square;
    for (const int s: square.sortedSquares(a)) cout << s << " ";

    return 0;
}
