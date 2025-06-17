#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k; 
int arr[100001];
int dp[100001];


int rec(int level){
  //prunnig 
   if(level<0){
    return 0;
   }
     
  //base case 
  if(level==0){
    return 0;
  }

  //caching 
  
  //computation 
     int ans=1e9;
     for(ll i=level-1;i>=max(level-k,0); i-- ){
        ans=min(ans,rec(i)+abs(arr[level]-arr[i]));
     }
  //save 
    return dp[level]=ans;

}


int main(){
cin>>n>>k;
for(ll i=0; i<n; i++){
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
cout<<rec(n-1)<<endl;


}