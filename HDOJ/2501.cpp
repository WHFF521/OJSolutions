#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

ll dp[35];

int main(){
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3;i<=30;i++){
        dp[i] = dp[i-1]+dp[i-2]*2;
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}