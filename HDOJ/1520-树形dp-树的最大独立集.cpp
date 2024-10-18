#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 6005;

int n;
int dp[mxlen][2];
vector<int> tree[mxlen];
void dfs(int x,int fa){
    for(int i=0;i<tree[x].size();i++){
        int v = tree[x][i];
        if(v==fa) continue;
        dfs(v,x);
        dp[x][1] += dp[v][0];
        dp[x][0] += max(dp[v][0],dp[v][1]);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) scanf("%d",&dp[i][1]);
        int x,y;
        while(scanf("%d%d",&x,&y)&&(x!=0||y!=0)){
            tree[y].push_back(x);
            tree[x].push_back(y);
        }
        dfs(1,0);
        printf("%d\n",max(dp[1][0],dp[1][1]));
        for(int i=1;i<=n;i++) tree[i].clear();
    }
    return 0;
}