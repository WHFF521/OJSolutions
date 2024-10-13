#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int mxlen = 1005;

vector<int> G[mxlen];
int n,m;
bool vis[mxlen];
void init(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) G[i].clear();
}

int euler(){
    for(int i=1;i<=n;i++){
        if(G[i].size()&1) return 0;
    }
    queue<int> q;
    int num = 0;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        num++;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    return num==n;
}
int main(){
    while(scanf("%d",&n)&&n){
        scanf("%d",&m);
        init();
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = euler();
        printf("%d\n",ans);
    }
    return 0;
}