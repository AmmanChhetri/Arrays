


// Problem Link - https://www.codingninjas.com/studio/problems/linear-search_6922070


#include <bits/stdc++.h>
using namespace std;


// we need to return the index of the first occurence of the given element if it is present...otherwise return -1...
int linearSearch(vector<int> &nums, int x) {

    int n = nums.size();

    int ans = -1;
    for(int i = 0;i<n;i++) {
        if(nums[i] == x) {
            return i;
        }
    }

    return ans;

    // Time Complexity is O(n)..
    // Space Complexity is O(1)..
}


int main() {


    vector<int> nums = {6,7,8,4,1};
    int x1 = 8;
    int x2 = 5;

    cout<<linearSearch(nums,x1)<<endl;
    cout<<linearSearch(nums,x2)<<endl;

    return 0;
}