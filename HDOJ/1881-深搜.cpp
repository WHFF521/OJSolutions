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
struct node{
    int happy;
    int cost;
    int leave;
    bool operator < (const node &a) const{
        return leave<a.leave;
    }
}group[35];
int n,ans;

void dfs(int cnt,int time,int sum){
    if(cnt==n){
        ans = max(ans,sum);
        return ;
    }
    if(time+group[cnt+1].cost<=group[cnt+1].leave){
        dfs(cnt+1,time+group[cnt+1].cost,sum+group[cnt+1].happy);
    }
    dfs(cnt+1,time,sum);
}

int main(){
    while(scanf("%d",&n)&&n>=0){
        int x,y,z;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            group[i] = {x,y,z};
        }
        sort(group+1,group+1+n);
        ans = 0;
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}