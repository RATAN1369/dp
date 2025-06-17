#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
int arr[100100];
int dp[100100];
//LIS 
//TC->O(n^2)

int rec(int level){
  //prunnig 
    if(level<0) return 0;

  //base case 

  //caching 
  if(dp[level]!=-1) return dp[level];

  //computation 
        int ans=1;
        for(int prev=0; prev<level; prev++){
            if(arr[prev]<arr[level]){
                ans=max(ans,1+rec(prev));
            }
        }


  //save 
  return dp[level]=ans;



}


int main(){
cin>>n;
for(int i=0; i<n; i++){
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
int sol=0;
for(int i=0; i<n; i++){
    sol=max(sol,rec(i));
}



}