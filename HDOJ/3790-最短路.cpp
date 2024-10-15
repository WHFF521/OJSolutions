#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
const int mxlen =1005;
const int inf = 0x3f3f3f3f;
struct node{
    int other;
    int len;
    int price;
};
vector<node> G[mxlen];
int dis[mxlen],cost[mxlen];
bool vis[mxlen];
int n,m,s,t;

void dijkstra(){
    memset(dis,inf,sizeof(dis));
    memset(cost,inf,sizeof(cost));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    cost[s] = 0;
    priority_queue<pair<int,int> >q;
    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].other;
            int len = G[u][i].len;
            int price = G[u][i].price;
            if(dis[v]>dis[u]+len){
                dis[v] = dis[u]+len;
                // 注意这里是强制更改花费，因为路径最短优先级最高
                cost[v] = cost[u]+price;
                q.push({-dis[v],v});
            }else if(dis[v]==dis[u]+len){
                cost[v] = min(cost[v],cost[u]+price);
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)&&(n!=0&&m!=0)){
        int a,b,d,p;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&a,&b,&d,&p);
            G[a].push_back({b,d,p});
            G[b].push_back({a,d,p});
        }
        scanf("%d%d",&s,&t);
        dijkstra();
        printf("%d %d\n",dis[t],cost[t]);
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
    }
    return 0;
}