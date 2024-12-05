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
const int mxlen = 1e7+10;

struct node{
    int x,y;
}points[5005];

struct airport{
    int x,y;
    int r;
    int ping;
}airports[5005];
int n,m;

int pre[mxlen],last[mxlen],other[mxlen],len[mxlen],l;
void add(int x,int y,int z){
    l++;
    pre[l] = last[x];
    last[x] = l;
    other[l] = y;
    len[l] = z;
}
void add_edge(){
    for(int i=n+1;i<=m+n;i++){
        int x = airports[i-n].x;
        int y = airports[i-n].y;
        int r = airports[i-n].r;
        int ping = airports[i-n].ping;
        for(int j=1;j<=n;j++){
            int px = points[j].x;
            int py = points[j].y;
            if(abs(px-x)<=r && abs(py-y)<=r){
                add(i,j,ping);
                add(j,i,ping);
            }
        }
    }
    
}
int dis[5005*2];
int vis[5005*2];
void dijkstra(){
    for(int i=1;i<=n+m;i++){
        dis[i] = 1e9;
    }
    dis[1] = 0;
    priority_queue<pair<int,int> >q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i=last[x];i;i=pre[i]){
            int y = other[i];
            if(dis[y]>dis[x]+len[i]){
                dis[y] = dis[x]+len[i];
                q.push(make_pair(-dis[y],y));
            }
        }
    }
    if(dis[n]==1e9) printf("Nan\n");
    else
    printf("%d\n",dis[n]/2);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&points[i].x,&points[i].y);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&airports[i].x,&airports[i].y,&airports[i].r,&airports[i].ping);
    }
    add_edge();
    dijkstra();

    return 0;
}