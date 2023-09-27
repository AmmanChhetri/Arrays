


// Problem Link - https://leetcode.com/problems/rotate-array/description/


#include <bits/stdc++.h>
using namespace std;


// BruteForce
// upon closer observation what we observe is that...for a given k...the first (n-1-k) elements will go to the last...and the 
// elements from (n-k) to last index ...will come in front...where n = size of array...
void rotate_Brute(vector<int> &nums, int k) {
    int n = nums.size();

    // we know if n = nums.size()...then after every nth rotation the array becomes what it was at initial state...example if
    // n = 4 where nums = {3,1,6,4} ...so after every 4 rotations the array will again become {3,1,6,4}...which means...if i say
    // k = 60...then nums after rotating 60 times will be {3,1,6,4} again ..as k=60 is multiple of n=4...so first check we 
    // have to do it how many times we need to rotate..its not like  if k=60 ..we will rotate it 60 times...so
    k = k % n;


    

    vector<int> temp(k);

    // elements from index [n-k,n) of nums array...will come to the front...
    for(int i = n-k;i<n;i++) {
        temp[i-n+k] = nums[i];
    }

    // elements from index [0,n-k-1] of nums array..will go to the end..so for this we will just shift the elements to the right
    // by k units..
    for(int i = n-k-1;i>=0;i--) {
        nums[i+k] = nums[i];
    }
    

    // copying the temp array to the front
    for(int i = 0;i<k;i++) {
        nums[i] = temp[i];
    }

    cout<<"Array after rotating it for "<<k<<" times towards right will be : "<<endl;
    for(int i = 0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
    


    // Time Complexity is O(n)
    // Space Complexity is O(k)
}









// Optimal
// Now we have a very good optimal approach for this problem...which we can implement without extra space...
// just reverse the last k elements ....and then reverse the first n-k elments....then reverse the whole array...
void reverse(vector<int> &nums, int i, int j) {

    while(i <= j) {
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}


void rotate_Optimal(vector<int> &nums, int k) {
    int n = nums.size();
    
    // This is important step as mentioned in the BruteForce method...apart from it is also required here ...suppose if n = 5 
    // and k = 101...so if put this value in the beow reverse function call we have reverse(nums,0,-95)..which gives us indexing
    // error ..so to fix it..we also need to do k%n ...so to bring k down..
    k = k%n; 
    
    
    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);
    
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

    rotate_Brute(nums1,k);
    cout<<endl;
    rotate_Optimal(nums2,k);

    return 0;
}