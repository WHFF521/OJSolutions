#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 1e5+10;
int dp[mxlen];
int num[4];
int money[] = {0,1,2,5};
int main(){
    // 面值为1.2.5的硬币不能组成的最小面值
    int n1,n2,n5;
    while(1){
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&num[1],&num[2],&num[3]);        
        if(num[1]==0&&num[2]==0&&num[3]==0) break;
        int sum = num[1]+2*num[2]+5*num[3];
        dp[0] = 1;
        // 多重背包
        for(int i=1;i<=3;i++){
            for(int j=sum;j>=money[i];j--){
                for(int k=1;k*money[i]<=j&&k<=num[i];k++){
                    dp[j] = max(dp[j],dp[j-k*money[i]]);
                }
            }
        }
        int ans = sum+1;
        for(int i=0;i<=sum;i++){
            if(!dp[i]) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}