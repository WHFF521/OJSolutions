#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 2e5+5;
int n,k;
vector<int> tree[mxlen];
int num[mxlen];

int ans;
void init(){
    ans = 0;
    for(int i=1;i<=n;i++) tree[i].clear();
}

void dfs(int x,int fa){
    num[x] = 1;
    for(int i=0;i<tree[x].size();i++){
        int v = tree[x][i];
        if(v == fa) continue;
        dfs(v,x);
        num[x]+=num[v];
    }
    // 一条边左边和右边的节点个数大于等于k就可以为答案贡献1
    if(num[x]>=k&&n-num[x]>=k) ans++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        int x,y;
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        dfs(1,0);
        cout<<ans<<endl;
        init();
    }

    return 0;
}