#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int n;
ll dp[55][3][3];
int main(){
    dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i==j) continue;
            dp[2][i][j] = 1;
        }
    }
    for(int i=3;i<=50;i++){
        for(int j=0;j<=2;j++){
            dp[i][j][0] = dp[i-1][j][1]+dp[i-1][j][2];
            dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][2];
            dp[i][j][2] = dp[i-1][j][0]+dp[i-1][j][1];
        }
    }
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            printf("3\n");
            continue;
        }
        ll ans = 0;
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(i==j) continue;
                ans += dp[n][i][j];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}