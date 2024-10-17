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

int n,m;

int main(){
    while(scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
        vector<int> cost;
        vector<double> p;
        vector<double> dp(10001,0);
        for(int i=0;i<m;i++){
            int x;double y;
            scanf("%d%lf",&x,&y);
            cost.push_back(x);
            p.push_back(y);
        }
        for(int i=0;i<m;i++){
            for(int j=n;j>=cost[i];j--){
                dp[j] = max(dp[j],1.0-(1.0-dp[j-cost[i]])*(1-p[i]));
            }
        }
        printf("%.1f%%\n",dp[n]*100);
    }
    return 0;
}