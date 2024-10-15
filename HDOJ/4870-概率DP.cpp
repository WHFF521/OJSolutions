#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
const int mxlen = 25;
double dp[mxlen];

int main(){
    double p;
    while(scanf("%lf",&p)!=EOF){
        dp[1] = 1/p;
        dp[2] = 1/p/p;
        double tot = dp[1]+dp[2];
        for(int i=3;i<=20;i++){
            dp[i] = (1+(1-p)*(dp[i-1]+dp[i-2]))/p;
            tot += dp[i];
        }
        printf("%.6lf\n",2*tot-dp[20]);
    }
    return 0;
}