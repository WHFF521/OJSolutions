#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 520;
int G[mxlen][mxlen];


int n,m;
int indegree[mxlen];
void init(){
    memset(G,0,sizeof(G));
    memset(indegree,0,sizeof(indegree));
}

void Topo(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]) continue;
        q.push(-i);
    }
    int cnt = 0;
    while(!q.empty()){
        int u = -q.top();
        q.pop();
        cnt++;
        if(cnt!=n) printf("%d ",u);
        else {
            printf("%d\n",u);
            break;
        }
        for(int i=1;i<=n;i++){
            if(i==u) continue;
            if(G[u][i]){
                indegree[i]--;
                if(!indegree[i]){
                    q.push(-i);
                    G[u][i] = 0;
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            // 数据有重边，题目没说。。。
            if(!G[x][y]) indegree[y]++;
            G[x][y] = 1;
        }
        Topo();
    }
    return 0;
}