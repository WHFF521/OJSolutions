#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 1e4;
int n;
struct node
{
    int x,y;
    int len;
}g[mxlen];
int cntG;
int a[mxlen][mxlen];
int father[mxlen];

bool cmp(node a,node b){
    return a.len<b.len;
}

int getfather(int x){
    if(father[x]==x) return x;
    father[x] = getfather(father[x]);
    return father[x];
}

void initG(){
    cntG = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            g[cntG].x = i;
            g[cntG].y = j;
            g[cntG++].len = min(a[i][j],a[j][i]);
        }
    }
    sort(g,g+cntG,cmp);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int x,y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                a[i][j]=x;
            }
        }
        int num;
        scanf("%d",&num);
        for(int i=1;i<=num;i++){
            scanf("%d%d",&x,&y);
            a[x][y]=a[y][x]=0;
        }

        initG();
        
        for(int i=1;i<=n;i++) father[i] = i;

        int ans = 0;
        int cntNow = 0;
        for(int i = 0;i<cntG;i++){
            int x = getfather(g[i].x);
            int y = getfather(g[i].y);
            if(x!=y){
                father[x] = y;
                ans+=g[i].len;
                cntNow++;
            }
            if(cntNow==n-1) break;
        }
        printf("%d\n",ans);
    }
    
    
    return 0;
}