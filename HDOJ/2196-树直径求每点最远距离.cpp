#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
const int mxlen = 1e4+5;
int n;
int diameterA,diameterB,dlength;
struct node{
    int v,len;
};

vector<node> G[mxlen];
int disA[mxlen],disB[mxlen];
void clean(){
    memset(disA,0,sizeof(disA));
    memset(disB,0,sizeof(disB));
    diameterA = diameterB = 0;
    dlength = 0;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
}
void find_diameter(int u,int fa,int depth,int &diameter){
    if(depth>=dlength){
        diameter = u;
        dlength = depth;
    }
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if(v==fa) continue;
        find_diameter(v,u,depth+G[u][i].len,diameter);
    }
}

void calc_dis(int u,int fa,int depth,int *dis){
    dis[u] = depth;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if(v==fa) continue;
        calc_dis(v,u,depth+G[u][i].len,dis);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int x,y;
        for(int i=2;i<=n;i++){
            scanf("%d%d",&x,&y);
            G[i].push_back({x,y});
            G[x].push_back({i,y});
        }
        find_diameter(1,0,0,diameterA);
        dlength = 0;
        find_diameter(diameterA,0,0,diameterB);
        calc_dis(diameterA,0,0,disA);
        calc_dis(diameterB,0,0,disB);
        for(int i=1;i<=n;i++){
            printf("%d\n",max(disA[i],disB[i]));
        }
        clean();
    }
    return 0;
}