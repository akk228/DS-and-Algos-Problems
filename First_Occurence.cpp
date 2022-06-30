//  First Occurence
//
/*  Given a sorted array of integers and a target integer, find the first occurrence of the target and return its index.
    Return -1 if the target is not in the array.
*/

#include <iostream>
#include<vector>
using namespace std;

int find_first_occurrence(vector<int> arr, int target) {
    int length = (int) arr.size();
    int first = 0, last = length - 1;
    int mid = first + (last - first)/2;
    
    if (length == 0) return -1;
    if (length == 1) {
        if (arr[0] == target){
            return 0;
        }else{
            return -1;
        }
    };
    
    while (first < last){
        if (arr[mid] >= target) {
            last = mid;
        }else{
            first = mid + 1;
        }
        mid = first + (last - first)/2;
    }
    
    if (arr[first] == target){
        return first;
    }else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> v = {0,2,3,10};
    cout << find_first_occurrence(v, -1) << endl;
    return 0;
}
