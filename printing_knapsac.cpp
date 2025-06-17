#include<bits/stdc++.h>
using namespace std;
#define ll long long

//0-1 knapsack 
//TC=no. of states *(1+ no. of transision )



int w[3003];
int v[3003];
int n;int W;

int dp[3003][3003];

vector<int> sol;

int rec(int level , int w_left){
    //pruning


    //basecase
    if(level==n){
        return 0;
    }
    //caching 
    if(dp[level][w_left]!=-1){
        return dp[level][w_left];
    }
    //transition 
    int ans=0;
    ans=rec(level+1,w_left);
    if(w_left>=w[level]){
        ans=max(rec(level+1,w_left-w[level])+v[level],ans);
    }
    dp[level][w_left]=ans;
    return ans;



}

void generate(int level, int w_left){
   if(level==n){
    return;
   }
   int donttake=rec(level+1,w_left);
   if(w[level]<=w_left){
        int take=rec(level+1,w_left-w[level])+v[level];
        if(donttake>take){
            generate(level+1,w_left);
        }else{
            sol.push_back(level);
            generate(level+1,w_left-w[level]);
        }

   }else{
         generate(level+1,w_left);
   }

}


int main(){
cin>>n;
for(ll i=0; i<n; i++){
    cin>>w[i];
}
for(ll i=0; i<n; i++){
    cin>>v[i];
}
cin>>W;
memset(dp,-1,sizeof(dp));
cout<<rec(0,W)<<endl;
generate(0,W);
for(auto it: sol){
  cout<<it<<" ";
}
cout<<endl;


}