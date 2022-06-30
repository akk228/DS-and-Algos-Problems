#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int first = 0, last = 0;
        
        while ( s[last] != '\0' ){
            last = first;
            while ( s[last] != ' ' and s[last] != '\0' ) last++;
            for (int i = 0; i < (last-first)/2; i++) swap(s[first+i], s[last-1-i]);
            first = last + 1;
        }
        return s;
    }
};

int main() {
    string str = "Hi there bitch lol";
    Solution rev;
    cout << rev.reverseWords(str) << endl;
    return 0;
}
