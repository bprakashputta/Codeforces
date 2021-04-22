// Given an array a of length n, you can do at most k operations of the following type on it:

// choose 2 different elements in the array, add 1 to the first, and subtract 1 from the second.
//  However, all the elements of a have to remain non-negative after this operation.
// What is lexicographically the smallest array you can obtain?

// An array x is lexicographically smaller than an array y if there exists an index i such that xi<yi, 
// and xj=yj for all 1≤j<i. Less formally, at the first index i in which they differ, xi<yi.

#include<iostream>
#include<vector>
using namespace std;

void titForTat(vector<int> arr,int n,int k){
    // given 100 is a number 
    // any number less than 100 is
    // lexographically smaller than 100
    for(int i=0; i<n-1;i++){
        if(k>0){
            if(arr[i] < k){
                k = k - arr[i];
                arr[n-1] += arr[i];
                arr[i] = 0;
            }else{
                arr[i] = arr[i] - k;
                arr[n-1] += k;
                k = 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // cout<<endl;
        titForTat(arr,n,k);
    }
return 0;
}