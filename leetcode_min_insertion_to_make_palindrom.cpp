class Solution {
public:
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

    int minInsertions(string s) {
          a=s;
         reverse(s.begin(),s.end());
          b=s;
        n=a.size();m=b.size();
        memset(dp,-1,sizeof(dp));
        return a.size()-rec(0,0);
    }
};