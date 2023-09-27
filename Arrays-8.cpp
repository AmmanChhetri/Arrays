


// Problem Link - https://www.codingninjas.com/studio/problems/rotate-array_1230543


#include <bits/stdc++.h>
using namespace std;




// Brute Force
// we observe when we need to rotate the array to left by k times...then after rotation the starting k elements go at end ...
// and elements from [k,n) ...comes front...so i will store the value that needed to go to the back in an temp array..and 
// i will shift the part of the array to leftwards...that needed to come at front...
void rotateLeft_Brute(vector<int> &nums, int k) {

    int n = nums.size();

    k = k%n; // to bring down the value of k ...below n
    
    // copying the first k elments...
    vector<int> temp(k);
    for(int i = 0;i<k;i++) {
        temp[i] = nums[i];
    }
    
    // shifting the elements from [k,n) to the front...
    for(int i = k;i<n;i++) {
        nums[i-k] = nums[i];
    }


    // adding the elements stored in temp back to nums array....
    for(int i = n-k;i<n;i++){
        nums[i] = temp[i+k-n];  //initially i= n-k, therefore to make it 0 we do temps[i+k-n]..which basically means n-k+k-n=0..
                                // that's how we get the logic to write temp[i+k-n]..because we know nums[i=n-k]=temp[0]..for 
                                // first time...
    }


    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }

    // Time Complexity is O(n) 
    // Space Complexity is O(k)

}






// Optimal
// reverse the first k numbers...then reverse the numbers from [k,n-1)..then reverse the whole array
void reverse(vector<int> &nums, int i, int j) {
    
    while(i <= j) {
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}


void rotateLeft_Optimal(vector<int> &nums, int k) {

    int n = nums.size();
    
    k = k%n;

    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
    reverse(nums,0,n-1);

    cout<<endl;
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }


    // Time Complexity is O(n)
    // Space Complexity is O(1)


}




int main() {

    vector<int> nums1 = {1,2,3,4,5,6,7};
    vector<int> nums2 = {1,2,3,4,5,6,7};
    int k = 3;

    rotateLeft_Brute(nums1,k);
    rotateLeft_Optimal(nums2,k);
    return 0;
}

