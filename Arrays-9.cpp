


// Problem Link - https://leetcode.com/problems/move-zeroes/description/


#include <bits/stdc++.h>
using namespace std;





// BruteForce
// as we need to move 0's to the end...lets create a vector temp..which will store all the non-zero elements....in the same 
// order...after this we will replace all this number from temp ...to the front of nums....and make other numbers equals to zero
void moveZeros_Brute(vector<int> &nums) {

    vector<int> temp;
    int n = nums.size();

    for(int i = 0;i<n;i++) {
        if(nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    for(int i = 0;i<temp.size();i++) {
        nums[i] = temp[i];
    }

    // now number of non zero elements will be size of temp...
    int j = temp.size();

    // making all numbers after the non-zero elements to 0...
    for(int k = j;k<n;k++) {
        nums[k] = 0;
    }

    // printing the nums array....
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }

    // Time Complexity is O(n)
    // Space Complexity is O(temp.size())
}




// Optimal-
// intuition - as we are required to move all zeros to the end ...and all other non-zero elements to the front...and we have to
//             do this in-place...plus so we need to manipulate the positions of element...so we think of 2-pointers approach !!



// method - 1..
// logic - after dry running different examples we found out ....the below logic 
void moveZeros_Optimal_1(vector<int> &nums) {
    
    int n = nums.size();
    int i = 0;  // where i will insert the value 
    for(int j = 0;j<n;j++) {
        if(nums[i] == nums[j] && nums[i] == 0) {
            // as i is already pointing to a zero element....we move only j..so to search for non-zero element...
            continue;
        }else if(nums[i] == nums[j]) {
            // here nums[i] != 0 ...so we need to move both the pointers...because we want our pointer `i` at the index where
            // it has 0 element...
            i++;
            continue;
        }else if(nums[i] != nums[j]) {
            // as we have started both the pointers together(ie from index 0) ..so we know nums[i] == nums[j] ...if both are 
            // pointing to same index..whenever this case comes...i will be always pointing to a 0 element...
            swap(nums[i],nums[j]);
            i++;
        }
    }


    // printing the nums array....
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
    
    
}



// Method 2 - A bit easier to understand...
// Logic - So we want to put zeros in the end...which means...whenever we see a zero in front...that's not what we want right?
//         we want to move a non-zero element to this location...so what we will do is we place a pointer to the first zero
//         thas has occured...this will act as a point where we replace a non-zero element...we place 2nd pointer to just 1 
//         index ahead of where we found the first zero element...now we traverse this index to check for non-zero element...
//         if found we replace it with the pointer we placed at the first zero...and move this pointer ahead...
//  so in this way our one pointer is always pointing to the number 0...
void moveZeros_Optimal_2(vector<int> &nums) {

    int n = nums.size();

    int i = -1; // to store the index of first 0 element...
    for(int j = 0;j<n;j++) {
        if(nums[j] == 0) {
            i = j;
            break;
        }
    }


    // i will traverse all elements from index i+1...because elements before index i ...will definitely non zero...
    for(int k = i+1;k<n;k++) {
        if(nums[k] != 0) {
            swap(nums[i],nums[k]);
            i++; // our i will always be pointing to the 0 element...dry run for better understanding...
        }
    }
    


    // printing the nums array....
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }


    // Time Complexity is O(n)...because lets say we got the first 0 element at index x...which means for first loop O(x) ...
    //                 for second loop O(n-x)...which means total = O(x)+O(n-x) = O(n)...
    // Space Complexity is O(1)....

}





int main() {

    vector<int> nums = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    
    moveZeros_Brute(nums);
    cout<<endl;
    moveZeros_Optimal_1(nums);
    cout<<endl;
    moveZeros_Optimal_2(nums);

    return 0;
}