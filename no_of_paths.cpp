#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m; 
int arr[1003][1003];
int dp[1003][1003];

int rec(int r, int c){
  //prunnig 
    if(r<0 || c<0){
         return 0;
    }

  //base case 
    if(r==0 && c==0){
       return 1; 
    }
  //caching 
 if(dp[r][c] != -1) return dp[r][c];

  //computation 
     int ans=rec(r-1,c)+rec(r,c-1); 

  //save 
    
      return dp[r][c]=ans;


}


int main(){
cin>>n>>m;
for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
         cin>>arr[i][j];
    }
}
memset(dp,-1,sizeof(dp));
  cout<<rec(n-1,m-1)<<endl;



}