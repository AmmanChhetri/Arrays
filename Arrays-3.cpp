


// Problem Link - https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957


#include <bits/stdc++.h>
using namespace std;



// Brute force
bool check_Brute(vector<int>& nums) {

    vector<int> temp = nums;
    sort(temp.begin(),temp.end());

    if(temp == nums) {
        return true;
    }

    return false;

    // Time Complexity is O(logn) 
    // Space Complexity is O(n) ...for using vector temp...
        
}



// Optimal 
bool check_Optimal(vector<int>& nums) {

    int n = nums.size();

    for(int i = 1;i<n;i++) {
        if(nums[i] < nums[i-1]) {
            return false;
        }
    }

    return true;

    // Time Complexity is O(n)...
    // Space Complexity is O(1)...
        
}



int main() {
    vector<int> nums1 = {3,4,5,1,2};
    vector<int> nums2 = {1,2,3};

    cout<<check_Brute(nums1)<<endl;
    cout<<check_Optimal(nums1)<<endl;

    cout<<check_Brute(nums2)<<endl;
    cout<<check_Optimal(nums2)<<endl;


    return 0;
}