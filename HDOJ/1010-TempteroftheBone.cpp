#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char mp[10][10];
int n,m,T;
bool vis[10][10];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

string ans;

int startX,startY,endX,endY;
void dfs(int x,int y,int step){
    if(ans=="YES") return;
    else if(step>T) return;
    else if(mp[x][y]=='D'&&step==T){
        ans = "YES";
        return;
    }

    // 剩余时间小于到终点的最短距离
    if(T-step<(abs(x-endX)+abs(y-endY))){
        return;
    }
    // 剩余时间剪去最短距离不是偶数
    if((T-step-(abs(x-endX)+abs(y-endY)))%2!=0){
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&mp[nx][ny]!='X'){
            vis[nx][ny]=true;
            dfs(nx,ny,step+1);
            vis[nx][ny]=false;
        }
    }
}
int main(){
    while(1){
        scanf("%d%d%d",&n,&m,&T);
        if(!n&&!m&&!T) break;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='S'){
                    startX=i;
                    startY=j;
                }else if(mp[i][j]=='D'){
                    endX=i;
                    endY=j;
                }
            }
        }
        ans = "NO";
        // vis记得清空
        memset(vis,false,sizeof(vis));
        // 起点要标记为已访问 
        vis[startX][startY]=true;
        dfs(startX,startY,0);
        cout<<ans<<endl;
    }
    return 0;
}