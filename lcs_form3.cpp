#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n,m;
string a,b;
string sol;
int dp[1001][1001];
int rec(int i, int j){

    //base case;
    if(i==n || j==m){
        return 0;
    }

    //caching 
    if(dp[i][j]!=-1) return dp[i][j];


    //computing 
    int ans=0;
    ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1));
    if(a[i]==b[j]){
        ans=max(ans,rec(i+1,j+1)+1);
    }
    return dp[i][j]=ans;

}
void generate(int i, int j){
     if(i==n || j==m){
        return;
    }
     int pos1=rec(i+1,j);
     int pos2=rec(i,j+1);
     int pos3=-1;
     if(a[i]==b[j]){
        pos3=rec(i+1,j+1);
     }
     if(pos3>=pos1 && pos3>=pos2){
        sol.push_back(a[i]);
        generate(i+1,j+1);
     }else if(pos1>=pos3 && pos1>=pos2){
        generate(i+1,j);
     }else{
generate(i,j+1);
     }


}


int main(){
cin>>n>>m;
cin>>a>>b;
memset(dp,-1,sizeof(dp));
cout<<rec(0,0)<<endl;;
generate(0,0);
cout<<sol<<endl;


}