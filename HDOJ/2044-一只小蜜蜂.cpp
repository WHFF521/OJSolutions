#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
ll dp[100];

int main(){
    int T;
    scanf("%d",&T);
    dp[0]=1;
    dp[1]=1;
    dp[2] = 1;
    int pos = 3;
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int n = b-a+1;
        if(dp[n]) {
            printf("%lld\n",dp[n]);
            continue;
        }else {
            for(int i=pos;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            pos = n+1;
            printf("%lld\n",dp[n]);
        }
    }
    return 0;
}