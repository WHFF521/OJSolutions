#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int value[1001],volume[1001];
int dp[1001];
int main(){
    int T;
    cin >>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int N,V;
        cin >> N >> V;
        for(int i=1;i<=N;i++) scanf("%d",&value[i]);
        for(int i=1;i<=N;i++) scanf("%d",&volume[i]);
        for(int i=1;i<=N;i++){
            for(int j=V;j>=volume[i];j--){
                dp[j] = max(dp[j],dp[j-volume[i]]+value[i]);
            }
        }
        cout << dp[V] << endl;
    }
    return 0;
}