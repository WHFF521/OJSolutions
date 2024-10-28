#include<bits/stdc++.h>
using namespace std;
const int mxlen = 4e5+5;
int n;
int pre_ans;
int w[mxlen];
int father[mxlen];
int now_root = 1;
vector<int> broken[mxlen];
vector<int> g[mxlen];
struct node{
    int weight;
    int index;
};

bool check_relation(int u,int v){
    for(int i=0;i<broken[u].size();i++){
        if(broken[u][i]==v) return 0;
    }
    return 1;
}
void find_father(int u,int fa){
    father[u] = fa;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa) continue;
        if(!check_relation(u,g[u][i])) continue;
        find_father(g[u][i],u);
    }
}
int change(int v){
    if(!pre_ans) return v;
    return v^pre_ans;
} 

int dfs_weight(int u,int fa,int x){
    int ans = 0;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa) continue;
        if(!check_relation(u,g[u][i])) continue;
        ans+=dfs_weight(g[u][i],u,x);
    }
    if(w[u]>x) ans++;
    return ans;
}
int find_heaviest(int u,int fa){
    int ans = w[u];
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa) continue;
        if(!check_relation(u,g[u][i])) continue;
        ans = max(ans,find_heaviest(g[u][i],u));
    }
    return ans;
}

node find_minw_minindex(int u,int fa){
    node tmp = {w[u],u};
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa) continue;
        if(!check_relation(u,g[u][i])) continue;
        node son = find_minw_minindex(g[u][i],u);
        if(son.weight<tmp.weight){
            tmp.weight = son.weight;
            tmp.index = son.index;
        }else if(son.weight==tmp.weight){
            if(son.index<tmp.index){
                tmp.weight = son.weight;
                tmp.index = son.index;
            }
        }
    }
    return tmp;
}
void solve(int op){
    int u,x;
    // ask how many points' weight more than v in u subtree
    if(op==1){
        cin>>u>>x;
        u = change(u);
        x = change(x);
        pre_ans = dfs_weight(u,father[u],x);
        cout<<pre_ans<<endl;
    }else if(op==2){
        cin>>u>>x;
        u = change(u);
        x = change(x);
        w[u] = x;
    }else if(op==3){
        cin>>u>>x;
        u = change(u);
        x = change(x);
        n++;
        g[n].push_back(u);
        g[u].push_back(n);
        father[n] = u;
        w[n] = x;
    }else if(op==4){
        cin>>u;
        u = change(u);
        broken[u].push_back(father[u]);
        broken[father[u]].push_back(u);
        find_father(u,-1);
        pre_ans = find_heaviest(u,father[u]);
        cout<<pre_ans<<endl;
    }else if(op==5){
        cin>>u;
        u = change(u);
        node temp = find_minw_minindex(u,father[u]);
        pre_ans = temp.index;
        cout<<pre_ans<<endl;
    }else if(op==6){
        cin>>u;
        u = change(u);
        find_father(u,-1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while(T--){
        int m;
        cin>>n;
        int x,y;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }     
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }

        find_father(now_root,-1);
        cin>>m;
        int op;
        pre_ans = 0;
        for(int i=1;i<=m;i++){
            cin>>op;
            solve(op);
        }
    }
    return 0;
}