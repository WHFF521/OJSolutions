#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 125;
ll dp[mxlen][mxlen];

// 值为n的数，划分数中最大值为m
ll find(ll n,ll m){
    if(dp[n][m]) return dp[n][m];
    if(n==1||m==1){
        dp[n][m] = 1;
    }
    else if(n<=m){
        // 显然最大值只能是n，最大值只有n-1的划分数+上n=n
        dp[n][m] = find(n,n-1)+1;
    }
    else if(n>m){
        // 最大值为m-1的划分数 + （m+值为n-m最大值为m的划分数）
        dp[n][m]=find(n,m-1)+find(n-m,m);
    }
    return dp[n][m];

}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",find(n,n));
    }
    return 0;
}