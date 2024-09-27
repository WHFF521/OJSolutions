#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 1005;
int k,girls,boys;
int vis[mxlen];
int match[mxlen];
int partner[mxlen][mxlen];
int ans;

int dfs(int x){
    for(int i=1;i<=boys;i++){
        if(!partner[x][i]||vis[i]) continue;
        vis[i] = 1;
        if(!match[i]||dfs(match[i])){
            match[i] = x;
            return 1;
        }
    }
    return 0;
}
void find(){
    memset(match,0,sizeof(match));
    ans = 0;
    for(int i=1;i<=girls;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)){
            ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d",&k)&&k){
        scanf("%d%d",&girls,&boys);
        int x,y;
        memset(partner,0,sizeof(partner));
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            partner[x][y] = 1;
        }
        find();
    }
    return 0;
}