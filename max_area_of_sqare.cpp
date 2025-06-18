    #include<bits/stdc++.h>
    using namespace std;

    int arr[1001][1001];
    int dp[1001][1001];
    int n;int m;
    int rec(int r, int c){
            if(r<0 || c<0){
                return 0;
            }
            //caching
            if(dp[r][c]!=-1) return dp[r][c];
            

            int ans=0;
            if(arr[r][c]==1){
                ans = 1 + min({rec(r - 1, c), rec(r - 1, c - 1), rec(r, c - 1)});
            }
            return dp[r][c]=ans;



    }
    void solve() {
        cin>>n;
        cin>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
                dp[i][j]=-1;
            }
        }
           for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1 && dp[i][j]==-1){
                    rec(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]>0) cnt=max(cnt,dp[i][j]*dp[i][j]);
            
        }
        }
        cout<<cnt<<endl;
        }

        int main(){
            int tt; cin>>tt;
            while(tt--){
                solve();
            }
        }
 