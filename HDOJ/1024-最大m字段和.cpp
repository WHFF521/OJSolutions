#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 1e6+5;
const int inf = 0x3f3f3f3f;
int n,m;
ll dp[mxlen];
ll a[mxlen];
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        // 用memset会超时
        //memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            dp[i] = 0;
        }
        for(int i=1;i<=m;i++){
            ll pre = dp[i-1];
            ll pre_max = -inf;
            for(int j=i;j<=n-m+i;j++){
                pre_max = max(pre_max,pre);
                pre = dp[j];
                if(j!=i) dp[j] = max(pre_max,dp[j-1])+a[j];
                else dp[j] = pre_max+a[j];
            }
        }
        ll ans = -inf;
        for(int i=m;i<=n;i++){
            ans = max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}