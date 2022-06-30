/*
 Given a string s, find the length of the longest substring without repeating characters.
 */
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned long length = s.size();
        int first = 0;
        int i;
        int longest_sub_str = 0;
        int current_length = 0;
        for (int last = 0; last < length; last ++){
            i = first;
            while (s[i] != s[last] && i < last){
                i++;
            }
            if (i < last) {
                first = i + 1;
            }
            current_length = last-first+1;
            if (current_length > longest_sub_str) longest_sub_str = current_length;
        }
        
        return longest_sub_str;
    }
};

int main() {
    string s = "avc1eertg";
    Solution check;
    cout << check.lengthOfLongestSubstring(s) << endl;
    return 0;
}
