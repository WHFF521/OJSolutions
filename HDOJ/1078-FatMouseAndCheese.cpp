#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen =105;
int n,k;
int dp[mxlen][mxlen];
int a[mxlen][mxlen];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];
    int mx = a[x][y];
    for(int i=1;i<=k;i++){
        for(int j=0;j<4;j++){
            int nx = x+i*dx[j];
            int ny = y+i*dy[j];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]>a[x][y]){
                mx = max(mx,a[x][y]+dfs(nx,ny));
            }
        }
    }
    dp[x][y] = mx;
    return mx;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==-1&&k==-1) break;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        cout<<dfs(1,1)<<endl;
    }
    return 0;
}