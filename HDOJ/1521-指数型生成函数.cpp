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
ll fac[15];
double countArrangements(const vector<int>& quantities, int m){
    int n = quantities.size();
    // dp[i] 表示选 i 个物品的排列数
    vector<double> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int quantity = quantities[i];
        vector<double> temp(m + 1, 0);
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= quantity && j + k <= m; ++k) {
                temp[j + k] += dp[j] / fac[k];
            }
        }
        dp = temp;
    }
    return dp[m]*fac[m];
}

void init(){
    fac[0] = 1;
    for(int i=1;i<=10;i++){
        fac[i] = fac[i-1]*i;
    }
}
int main(){
    int n,m;
    init();
    // n个物品，每个物品有quantities[i]个，选m个物品的排列数
    while(scanf("%d%d",&n,&m)!=EOF){
        vector<int> quantities;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            quantities.push_back(x);
        }
        double ans = countArrangements(quantities,m);
        printf("%.0lf\n",ans);
    }
    return 0;
}