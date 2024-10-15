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
const int mxlen = 1005;
double dp[mxlen][mxlen];
struct node{
    double p_self,p_right,p_down;
}G[mxlen][mxlen];

int main(){
    // dp[i][j]指的是从(i,j)到终点的期望消耗魔法量
    // 终点的期望消耗魔法量为0，起点的期望消耗魔法量未知，所以采用逆推的方式
    // dp[i][j] = p1*(dp[i][j]+2)+p2*(dp[i+1][j]+2)+p3*(dp[i][j+1]+2)
    // p1+p2+p3=1
    int R,C;
    while(scanf("%d%d",&R,&C)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(G,0,sizeof(G));
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                double a,b,c;
                scanf("%lf%lf%lf",&a,&b,&c);
                G[i][j] = {a,b,c};
            }
        }
        dp[R][C]=0;
        for(int i=R;i>=1;i--){
            for(int j=C;j>=1;j--){
                if(i==R&&j==C) continue;
                if(fabs(1.0-G[i][j].p_self)<1e-8){
                    dp[i][j] = 0;
                }else {
                    dp[i][j] = (G[i][j].p_down*dp[i+1][j]+G[i][j].p_right*dp[i][j+1]+2.0)/(1.0-G[i][j].p_self);
                }
            }
        }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}