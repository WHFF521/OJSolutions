#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 105;
char s1[mxlen],s2[mxlen];
int dp[mxlen][mxlen];
int flag[mxlen][mxlen];

void print_name(int x,int y){
    if(x==0&&y==0) return;
    if(flag[x][y]==0){
        print_name(x-1,y-1);
        printf("%c",s1[x]);
    }else if(flag[x][y]==-1){
        print_name(x,y-1);
        printf("%c",s2[y]);
    }else {
        print_name(x-1,y);
        printf("%c",s1[x]);
    }
}
int main(){
    while(scanf("%s%s",s1+1,s2+1)!=EOF){
        memset(dp,0,sizeof(dp));
        int len1 = strlen(s1+1);
        int len2 = strlen(s2+1);
        for(int i=0;i<=len1;i++) flag[i][0] = 1;
        for(int i=0;i<=len2;i++) flag[0][i] = -1;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    flag[i][j] = 0;
                }else if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    flag[i][j] = -1;
                }else {
                    dp[i][j] = dp[i-1][j];
                    flag[i][j] = 1;
                }
            }
        }
        print_name(len1,len2);
        printf("\n");
    }
    return 0;
}
