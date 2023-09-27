


// Problem Link - https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278


#include <bits/stdc++.h>
using namespace std;



// Brute Force
// as we need to rotate the array left only once...so the 2nd element becomes 1st element...3rd element becomes 2nd element...
// and so on..and the first element of the array goes to the last position....
vector<int> rotateArray_Brute(vector<int>& arr, int n) {
    
    vector<int> temp;
    for(int i = 1;i<n;i++) {
        temp.push_back(arr[i]);
    }

    temp.push_back(arr[0]);

    return temp;

    // Time Complexity is O(n)
    // Space Compexity is O(n)
}







// Optimal 
// We are using a vector to store the rotated array...but we can do it in the same array...
vector<int> rotateArray_Optimal(vector<int> &arr, int n) {

    int temp = arr[0];

    for(int i = 0;i<n;i++) {
        arr[i] = arr[i+1];
    }
    
    arr[n-1] = temp;
    return arr;

    // Time Complexity is O(n)...
    // Space Complexity is O(1) ..as we are not using extra space to solve the problem...but yes if the interviewer ask about 
    // the space we are using for the algorithm...than space Complexity is O(n)..as we are using the given array itself...
    // So u should be clear about this ...
    
}


int main() {
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    vector<int> ans = rotateArray_Brute(arr,n);
    for(int i = 0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    vector<int> sol = rotateArray_Optimal(arr,n);
    for(int i = 0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}