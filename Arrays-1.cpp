


// Problem Link - https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279


#include <bits/stdc++.h>
using namespace std;




// BruteForce
int largestElement_Brute(vector<int> &arr, int n) {

    sort(arr.begin(),arr.end());

    return arr[n-1];
    
    // Time Complexity is O(nlogn) ...as we are using inbuilt sort
    // Space Complexity is O(1)...

}






// Optimal Approach
int largestElement_Optimal(vector<int> &arr, int n) {

    int maxi = INT_MIN;

    for(int i = 0;i<n;i++) {
        maxi = max(maxi,arr[i]);
    }

    return maxi;

    // Time Complexity is O(n) ...as we are running a single loop 
    // Space Complexity is O(1) ....

}


int main() {

    vector<int> arr = {5,9,3,4,8,4,3,10};
    int n = arr.size();

    cout<<largestElement_Brute(arr,n)<<endl;
    cout<<largestElement_Optimal(arr,n)<<endl;
    

    return 0;
}