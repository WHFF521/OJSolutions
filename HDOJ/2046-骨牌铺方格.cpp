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
ll dp[55];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=50;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",dp[n]);
    }
    return 0;
}