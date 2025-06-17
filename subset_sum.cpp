#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back



int n;int T;

int dp[101][10001];
int arr[101];
vector<ll> sol;


int rec(int level, int target){
//pruning
if(target<0){
    //invalid
    return 0;
}
//basecase
if(level==n){
    if(target==0){
        return 1;
    }else{
        return 0;
    }
}
//caching 
if(dp[level][target]!=-1) return dp[level][target];
//compuattion 
int ans=0;
if(rec(level+1,target-arr[level])){
    ans=1;
}
if(rec(level+1,target)){
    ans=1;
}
//save and return 
return dp[level][target]=ans;
}
void generation(int level,int target){
    if(level==n) return ;
    else{
        if(rec(level+1,target-arr[level])){
               sol.pb(arr[level]);
               generation(level+1,target-arr[level]);
             }else{
                generation(level+1,target);
             }
    }
}


int main(){
cin>>n;
for(ll i=0; i<n; i++){
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
//test cases
int t; cin>>t;
while(t--){
cin>>T;
cout<<rec(0,T)<<endl;
}


}