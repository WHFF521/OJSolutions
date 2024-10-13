#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const int mxlen = 105;
int n;
struct node{
    int u,v,w;
}edge[mxlen*mxlen];
int father[mxlen];

int getfather(int x){
    if(father[x]==x) return x;
    father[x] = getfather(father[x]);
    return father[x];
}

void init(){
    for(int i=1;i<=n;i++) father[i] = i;
}

int main(){
    while(scanf("%d",&n)&&n){
        init();
        int m = n*(n-1)/2;
        int a,b,c,d;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            // 已经有的道路成本设为0
            if(d) edge[i] = {a,b,0};
            else edge[i] = {a,b,c};
        }
        sort(edge+1,edge+1+m,[](node a,node b){
            return a.w<b.w;
        });
        int sum = 0;
        int ans = 0;
        for(int i=1;i<=m;i++){
            int fu = getfather(edge[i].u);
            int fv = getfather(edge[i].v);
            if(fu!=fv){
                father[fu] = fv;
                ans += edge[i].w;
                sum++;
            }
            if(sum==n-1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}