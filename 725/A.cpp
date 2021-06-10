// 1538 A Stone Game
// This is not the actual solution to the problem,
// there is another condition in it, which I didn't 
// understand.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int stoneGame(vector<int> arr, int n){
    int l = 0, r = n-1;
    int lval = 1, rval = *max_element(arr.begin(), arr.end());
    bool lf = false, ri = false, rep = true;
    while(l<r){
        if(arr[l]==lval){
            l++;
            lf=true;
            if(lf && ri) break;
        } else if(arr[r]==rval){
            r--;
            ri=true;
            if(lf && ri) break; 
        } else if(arr[l]!=lval && arr[r]!=rval){
            if(rep){
                l++;
                rep = false;
            }else{
                r--;
                rep = true;
            }
        }
    }
    cout<<"l-"<<l<<" r-"<<r<<endl;
return r-l+1;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout << stoneGame(arr,n) <<endl;
    } 
return 0;
}