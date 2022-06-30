{\rtf1\ansi\ansicpg1252\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /******************************************************************************\
\
                              Online C++ Compiler.\
               Code, Compile, Run and Debug C++ program online.\
Write your code in this editor and press "Run" button to compile and execute it.\
\
*******************************************************************************/\
\
#include <iostream>\
#include <vector>\
#include <cstdlib>\
using namespace std;\
\
class Solution \{\
public:\
    int findKthLargest(vector<int>& nums, int k) \{\
        \
        using std::swap;\
        //initialize boundaries\
        int first = 0, last = nums.size()-1;\
        while (first+1 < last)\{\
            //compare first & last\
            //if (first >= last ) return nums[k];\
            if ( nums[first] < nums[last] ) swap( nums[first], nums[last]);\
            \
            //put all the elements that are bigger than the first to the left\
            int sub_first = first, sub_last = last-1;\
            int barrier = nums[first];\
            while (sub_first < sub_last)\{\
                while ( barrier <= nums[sub_first] ) sub_first++;\
                while ( barrier >  nums[sub_last]  ) sub_last--;\
                if (sub_last > sub_first) swap( nums[sub_first], nums[sub_last]);\
            \};\
            swap( nums[first], nums[sub_first-1]);\
            /*\
            cout << "barrier element is " << nums[sub_first-1] << "at the position num "<<sub_first<<endl;\
            cout << endl;\
            for (int i = first; i<sub_first; i++)\{\
                cout << nums[i]<<" ";\
            \};\
            cout << endl;\
            */\
            \
            if ( sub_first-1 >= k-1) \{last = sub_first;\};\
            if ( sub_first-1 <= k-1) \{first = sub_first;\}\
            \
            //cout << endl << first << " " <<last << endl;\
        //\}\
        \}\
        if ( nums[first] < nums[last] ) swap ( nums[first], nums[last] );\
        return nums[k-1];\
    \}\
\};\
\
int main()\
\{\
    vector<int> nums = \{3,4,1,2,9,3,10\};\
    Solution lar;\
    for ( int s: nums) cout << s << " ";\
    /*\
    for (int i = 0; i<n; i++)\{\
        nums.push_back(rand()%10);\
        cout << nums[i]<<" ";\
    \};\
    */\
    cout << endl;\
    cout << lar.findKthLargest(nums, 2);\
    \
    return 0;\
\}\
}