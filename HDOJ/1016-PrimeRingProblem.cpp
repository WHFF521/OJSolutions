#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int n;
vector<int> prime;
bool not_prime[200];
void pre_work(int x){
    for(int i=2;i<=20;i++){
        if(!not_prime[i]) prime.push_back(i);
        for(int j:prime){
            if(i*j>x) break;
            not_prime[i*j] = true;
            if(i%j==0) break;
        }
    }
}

bool vis[25];
int b[25];

void dfs(int x){
    if(x>2){
        if(not_prime[b[x-1]+b[x-2]]){
            return;
        }
    }
    if(x==n+1){
        if(not_prime[b[n]+b[1]]) return;
        for(int i=1;i<=n;i++){
            printf("%d",b[i]);
            if(i!=n) printf(" ");
        }
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            b[x] = i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    // 只算到20会Wrong Answer。。。
    pre_work(100);
    int cnt = 0;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        vis[1] = 1;
        b[1] = 1;
        cnt++;
        printf("Case %d:\n",cnt);
        dfs(2);
        printf("\n");
    }
    return 0;
}