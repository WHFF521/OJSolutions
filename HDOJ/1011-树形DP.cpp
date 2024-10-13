#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int mxlen = 110;
int pre[mxlen*2],last[mxlen],other[mxlen*2],l;

void add(int x,int y){
    l++;
    pre[l] = last[x];
    last[x] = l;
    other[l] = y;
}

int n,m;
int dp[mxlen][mxlen];
bool vis[mxlen];
int bugs[mxlen],brains[mxlen];
void prepare(){
    l = 0;
    memset(pre,0,sizeof(pre));
    memset(last,0,sizeof(last));
    memset(other,0,sizeof(other));
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
}

void dfs(int x){
    vis[x] = true;
    // 向上取整
    int needed = (bugs[x]+19)/20;
    for(int i=needed;i<=m;i++){
        dp[x][i] = brains[x];
    }
    for(int p=last[x];p;p=pre[p]){
        int y = other[p];
        if(vis[y]) continue;
        dfs(y);
        for(int i = m;i>=needed;i--){
            for(int j=1;j<=i-needed;j++){
                //第x节点消耗i个士兵能获得的最大价值
                dp[x][i] = max(dp[x][i],dp[x][i-j]+dp[y][j]);
            }
        }
    }
}

int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(n==-1&&m==-1) break;
        prepare();
        for(int i=1;i<=n;i++){
            scanf("%d%d",&bugs[i],&brains[i]);
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(m==0){
            cout<<0<<endl;
            continue;
        }
        dfs(1);
        cout<<dp[1][m]<<endl;
    }

    return 0;
}