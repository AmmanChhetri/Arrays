


// Problem Link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


#include <bits/stdc++.h>
using namespace std;



// Optimal -
// Logic - We need to return true in 2 cases...first when the array is sorted ...second when the array is sorted but rotated...
//         otherwise we have to return false...if we observe carefully...the array is sorted if each element is greater than 
//         it's previous one...similarly we can say array is rotated if it breaks the ascending order only once...if it is 
//         breaking the order more than 1 times ...which means...the array is not rotated...now as we are given that last 
//         element and first element are connected...so if its a sorted array our last element always greater than the first 
//         element...

// what we observe is whenever we rotate the array ...there will always be one point where it is breaking the ascending order...
// say example ....our array was..{1,2,3,4,5} ...now if i rotate it once i have array as {5,1,2,3,4} ...so we see it is breaking
// the ascending order once at 5(5>1) ...so our logic is based on the same fact...we will count the number of times ascending 
// order is breaking..if it is breaking more than 1 times we return false...if it breaks the order exactly 1 times we return 
// true...point to be noted is even the array is sorted...it will still break the order for once..when we compare the last 
// element with the first element as they are conncected...

// if it is sorted or rotated it will always break the order 1 time....whenever the array is rotated..we observe there will be
// a junction before which everyone is sorted and after it also everyone is sorted...say example {3,4,5,1,2} ...here junction 
// point is between 5 and 1...so at this junction point is where the ascending order is been broke ...

// dry run for different examples for much clearity...
bool check_Optimal(vector<int> &nums) {

    int n = nums.size();
    int count = 0;

    for(int i = 0;i<n;i++) {
        // Here modulo is important because we need to compare the last element with the first one too...example {3,4,5,1,6}..if we
        // see this array is also breeaking the order once at 5(5>1)...but as the array is connected we saw it is breaking the order
        // again at 6 (6>3)...which means the array is not rotated...
        if(nums[i] > nums[(i+1)%n]) {
            count++;
        }

        if(count > 1) {
            return false;
        }
    }


    return true;

    // Time Complexity is O(n)...
    // Space Complexity is O(1)...

}




int main() {
    vector<int> nums1 = {3,4,5,1,2};
    vector<int> nums2 = {2,1,3,4};

    cout<<check_Optimal(nums1)<<endl;
    cout<<check_Optimal(nums2)<<endl;


    return 0;
}