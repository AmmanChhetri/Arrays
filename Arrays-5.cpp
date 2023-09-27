


// Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/


#include <bits/stdc++.h>
using namespace std;



// BruteForce .
// as i need to get the unique elements of the nums array in front..so we will first of all use set to get the unique elements..
// then we insert it in front of nums.....but this is not `in-place` ...as in question it is mentioned clearly we need to do it
// `in-place` ....
int removeDuplicates_Brute(vector<int> &nums) {

    set<int> st;
    
    for(int i = 0;i<nums.size();i++) {
        st.insert(nums[i]);
    }
    
    int m = st.size();    
    
    // set stores values in ascending order....
    int k = 0;
    for(auto it : st) {
        nums[k] = it;
        k++;
    }

    return m;

    // Time Complexity is O(nlogn) + O(n) ...O(nlogn) is for traversing the nums array inititally and inserting in set...
    // inserting in set takes logn time....O(n)...is for iterating set..at worst case we have to insert every element into the 
    // set....

    // Space Complexity is O(n) ....for using set...
}







// Optimal
// Intuition - As we need to manipulate the positions of elements of the array...we think of something like pointers approach
//             to be more precise regarding this problem...2-pointers approach...also we are given we need to do `in-place` so
//             it kinda push us to think towards pointers approach...

// Logic - Now we know we have to try using 2-pointers approach...we are given a sorted array having dublicates ...and we need
//         to get all unique elements in the front ....so we have to pick some numbers and place it in front inshort...so we 
//         keep a pointer at the beginning ...that will be used as the position to insert...and one pointer that will traverse
//         the array..to check which elements will come front....and we also know the first element of the array will be always
//         in its correct position....so we have to insert from index = 1...
int removeDuplicates_Optimal(vector<int> &nums) {

    int n = nums.size();
    
    int i = 0;    // for tracking the insert position
    for(int j = 1;j<n;j++) {
        if(nums[i] != nums[j]) {
            nums[i+1] = nums[j];
            i++;
        }
    }


    // we also need to return the number of unique elements....upon closer observations we observe that the number of elements
    // is always equals to the (i+1)..why because we are keeping our `i` to a particular element....till we find a different 
    // number that nums[i]...so at the end we will be pointing to some nums[i] ...that will be our last unique number...and as
    // we are filling unique elements continous in the array..which means number of elements is `i+1` ...(0-based indexing)
    // this return works for any case even if all the elements are unique.....
    // dry run with multiple examples..
    return i+1;

    // Time Complexity is O(n)..
    // Space Complexity is O(1)..

}



int main() {
    vector<int> nums = {1,1,2,2,2,3,3};
    
    cout<<removeDuplicates_Brute(nums)<<endl;
    cout<<removeDuplicates_Optimal(nums)<<endl;

    return 0;
}