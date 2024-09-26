#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 105;
int n,m,kind,s;
int dp[mxlen][mxlen];
int experience[mxlen],endure[mxlen];
int main(){
    while(scanf("%d%d%d%d",&n,&m,&kind,&s)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=kind;i++){
            scanf("%d%d",&experience[i],&endure[i]);
        }
        for(int i=1;i<=kind;i++){
            for(int j=endure[i];j<=m;j++){
                for(int k = 1;k<=s;k++){
                    dp[j][k]=max(dp[j][k],dp[j-endure[i]][k-1]+experience[i]);
                }
            }
        }
        int grade = -1;
        for(int i=0;i<=m;i++){
            if(dp[i][s]>=n){
                grade = m-i;
                break;
            }
        }
        cout<<grade<<endl;
    }
    return 0;
}