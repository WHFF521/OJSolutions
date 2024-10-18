#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 1005;
int dp[mxlen][2];

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        memset(dp,0,sizeof(dp));
        int len1 = s1.size();
        int len2 = s2.size();
        s1 = " "+s1;
        s2 = " "+s2;
        bool flag = 0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i]==s2[j]){
                    dp[j][flag] = dp[j-1][!flag]+1;
                }else {
                    dp[j][flag] = max(dp[j-1][flag],dp[j][!flag]);
                }
            }
            flag = !flag;
        }
        cout << dp[len2][!flag] << endl;
    }
    return 0;
}