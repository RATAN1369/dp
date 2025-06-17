#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m; 
int arr[1003][1003];
int dp[1003][1003];
int done[1003][1003];

int rec(int r, int c){
  //prunnig 
    if(r<0 || c<0){
         return 1e9;
    }

  //base case 
    if(r==0 && c==0){
       return arr[0][0]; 
    }
  //caching 
     if(done[r][c]){
        return dp[r][c];
     }

  //computation 
      int ans=1e9;
      if(r!=0){
        ans=min(ans,rec(r-1,c)+arr[r][c]);
      }  
      if(c!=0){
        ans=min(ans,rec(r,c-1)+arr[r][c]);
      }  

  //save 
     done[r][c]=1;
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
memset(done,0,sizeof(dp));
  cout<<rec(n-1,m-1)<<endl;



}