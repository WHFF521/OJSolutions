#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

ll dp[30];
ll sum[30];
int n,m;

int main(){
    dp[1] = 0;
    dp[2] = 1;
    sum[0] =1;
    sum[1] = 1;
    sum[2] = 2;
    for(int i=3;i<=20;i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
        sum[i] = sum[i-1]*i;
    }
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        printf("%lld\n",dp[m]*(sum[n]/sum[m]/sum[n-m]));
    }
    return 0;
}