


// Problem Link - https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960


#include <bits/stdc++.h>
using namespace std;




// BruteForce
vector<int> getSecondOrderElements_Brute(int n, vector<int> &a) {

    sort(a.begin(),a.end());
    

    // As array can contains duplicates...so its not like our secondLargest element will always be at a[n-2]...we can have 
    // array like {2,3,5,7,7}...so here second largest element is 5...not 7...similarly for secondSmallest element ...it is not
    // like our secondSmallest element will be at a[1]...
    int largest = a[n-1];
    int smallest = a[0];
    int secondSmallest = -1;
    int secondLargest = -1;


    // For finding Second Smallest...
    for(int i = 1;i<n;i++) {
        if(a[i] != smallest) {
            secondSmallest = a[i];
            break;
        }
    }
    
    // for finding Second largest...
    for(int i = n-2;i>=0;i--) {
        if(a[i] != largest) {
            secondLargest = a[i];
            break;
        }
    }

    return {secondLargest,secondSmallest};
    // Time Complexity is O(nlogn) + O(n) + O(n) ...due to sorting ..and for 2 loops ..suppose a worst case for finding the 
    // secondLargest element ..{1,7,7,7,7,7,7,7,7}..so the  loop will run for O(n)....but in the same array if we use the loop
    // to  find the secondSmallest element..we will get it instantly ...ie at a[1]...so what we observe is worser the 
    // calculation of oone thing...better the calculation of others....which means...    `TC - nlogn + O(n)`...

    // Space Complexity is O(1)...
    
}







// Better
// Logic - we will iterate 2 times...for first time we find the maximum or minimum of the array...in the next iteration we will
//         find a number that is just lesser(first lesset number) than maxi or just greater(first higher number) than mini...
vector<int> getSecondOrderElements_Better(int n, vector<int> &a) {
    
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++) {
        maxi = max(maxi,a[i]);
    }
    
    // to find a number just smaller number than maxi...we need to check if the current number is lesser than the maxi and is 
    // greater than the last closest number we have..
    int secondMaxi = INT_MIN;
    for(int i = 0;i<n;i++) {
        if(a[i] > secondMaxi && a[i] < maxi) {
            secondMaxi = a[i];
        }
    }

    int mini = INT_MAX;
    int secondMini = INT_MAX;

    for(int i = 0;i<n;i++) {
        mini = min(mini,a[i]);
    }


    for(int i = 0;i<n;i++) {
        if(a[i] > mini && a[i] < secondMini) {
            secondMini = a[i];
        }
    }


    return {secondMaxi,secondMini};
    // Time Complexity is O(n) ... for traversing 
    // Space Comlpexity is O(1)

}





// Optimal
vector<int> getSecondOrderElements_Optimal(int n, vector<int> &a) {
    
    int maxi = INT_MIN;
    int secondMaxi = INT_MIN;

    int mini = INT_MAX;
    int secondMini = INT_MAX;

    
    // for calculating maxi and secondMaxi
    for(int i = 0;i<n;i++) {
        if(a[i] > maxi) {
            secondMaxi = maxi;
            maxi = a[i];
        }else if(a[i] < maxi && a[i] > secondMaxi) {
            // there can be cases when the current number is lesser than maxi ....but still greater than secondMaxi...in this 
            // case we update secondMaxi...
            secondMaxi = a[i];
        }
    }


    // for calculating mini and secondMini
    for(int i = 0;i<n;i++) {
        if(a[i] < mini) {
            secondMini = mini;
            mini = a[i];            
        }else if(a[i] > mini && a[i] < secondMini) {

            secondMini = a[i];
        }
    }


    return {secondMaxi,secondMini};

    // Time Complexity is O(n) + O(n) 
    // Space Complexity is O(1)...

}



int main() {
    vector<int> a = {4,5,3,6,7};
    int n = a.size();

    vector<int> ans1 = getSecondOrderElements_Brute(n,a);
    vector<int> ans2 = getSecondOrderElements_Better(n,a);
    vector<int> ans3 = getSecondOrderElements_Optimal(n,a);

    cout<<ans1[0]<<" "<<ans1[1]<<endl;
    cout<<ans2[0]<<" "<<ans2[1]<<endl;
    cout<<ans3[0]<<" "<<ans3[1]<<endl;

    return 0;
}