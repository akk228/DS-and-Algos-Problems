/*
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

 In other words, return true if one of s1's permutations is the substring of s2.


 */
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len_1 = (int) s1.size(), len_2 = (int) s2.size();
        string aux_1, aux_2;
        for (int i = 0; i<len_1; i++) aux_1.push_back('0');
        bool check_right = 1, check_left = 1;
        
        for (int pos_2 = 0; pos_2 < len_2; pos_2++){
            //Look for onset
            if (s2[pos_2] == s1[0]){
                aux_2 = aux_1;
                //put onset to the auxiliary string
                aux_2[0] = s1[0];
                //look for other charcters
                while ( check_right == 1){
                    for (int k = 1; k < len_1; k++){
                        if ()
                    }
                }
                
            }
        }
        return 0;
    }
};

int main() {
    string s1 = "abc", s2 = "eidabooo";
    Solution check;
    cout << check.checkInclusion(s1, s2);
    return 0;
}
