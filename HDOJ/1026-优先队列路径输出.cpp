#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 105;
int n,m;
char graph[mxlen][mxlen];
struct node{
    int x,y;
    int prex,prey;
    int value;
    bool operator < (const node &a) const{
        return value>a.value;
    }
}trip[mxlen][mxlen];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[mxlen][mxlen];
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(trip,0,sizeof(trip));
    priority_queue<node> q;
    node start;
    start.x = 0;start.y = 0;
    start.prex = -1;start.prey = -1;
    start.value = 0;
    q.push(start);
    vis[0][0] = 1;
    node now,next;
    while(!q.empty()){
        now = q.top();
        q.pop();
        if(now.x==n-1&&now.y==m-1){
            return now.value;
        }
        for(int i=0;i<4;i++){
            next.x = now.x+dx[i];
            next.y = now.y+dy[i];
            if(next.x>=0&&next.y>=0&&next.x<n&&next.y<m){
                if(vis[next.x][next.y]) continue;
                char c = graph[next.x][next.y];
                if(c=='X') continue;
                vis[next.x][next.y] = 1;
                next.value = now.value+1;
                if(c>='0'&&c<='9') {
                    next.value += c-'0';
                    trip[next.x][next.y].value = c-'0';
                }
                trip[next.x][next.y].prex = now.x;
                trip[next.x][next.y].prey = now.y;
                q.push(next);
            }
        }
    }
    return -1;
}
int cnt;
void dfs(int x,int y){
    if(x==0&&y==0) return;
    dfs(trip[x][y].prex,trip[x][y].prey);
    printf("%ds:(%d,%d)->(%d,%d)\n",++cnt,trip[x][y].prex,trip[x][y].prey,x,y);
    while(trip[x][y].value){
        printf("%ds:FIGHT AT (%d,%d)\n",++cnt,x,y);
        trip[x][y].value--;
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",graph[i]);
        }
        int ans = bfs();
        if(ans == -1){
            printf("God please help our poor hero.\n");
        }else {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            cnt = 0;
            dfs(n-1,m-1);
        }
        printf("FINISH\n");
    }
    return 0;
}