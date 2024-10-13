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
const int mxlen = 210;
int n,m;
int pre[mxlen],last[mxlen],other[mxlen],l;
void add(int x,int y){
    l++;
    pre[l] = last[x];
    last[x] = l;
    other[l] = y;
}
int rudu[mxlen];
int vis[mxlen];
void init(){
    l=0;
    memset(pre,0,sizeof(pre));
    memset(last,0,sizeof(last));
    memset(other,0,sizeof(other));
    memset(rudu,0,sizeof(rudu));
    memset(vis,0,sizeof(vis));
}

void Topo(){
    queue<int> q;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(rudu[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for(int p=last[x];p;p=pre[p]){
            int y = other[p];
            if(vis[y]) {
                flag = true;
                break;
            }
            rudu[y]--;
            if(rudu[y]==0) q.push(y);
        }
        if(flag) break;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) {
            flag = true;
            break;
        }
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
}
int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(!n&&!m) break;
        init();
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            add(x,y);
            rudu[y]++;
        }
        Topo();
    }    
    return 0;
}