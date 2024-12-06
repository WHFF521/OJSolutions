#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
const int mxlen = 2005;

int n,k;
int dp[mxlen][mxlen];// 前i个物品选j对的最小代价
int w[mxlen];
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&w[i]);
        }
        sort(w+1,w+n+1);
        fill(dp[0],dp[0]+mxlen*mxlen,1e9);
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]));
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}