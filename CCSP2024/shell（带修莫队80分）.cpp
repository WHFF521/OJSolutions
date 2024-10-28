#include<bits/stdc++.h>
using namespace std;
const int mxlen = 1e5+1e4+15;
int n;

vector<int> a;

bool vis[mxlen*2];
int block = 2589;
struct Query{
    int id,l,r,t;
}q[mxlen];
struct Modify{
    int pos,col,lst;
}c[mxlen];
int cnt[mxlen];
int bi[mxlen];

bool cmp(const Query &a, const Query &b){
int al = bi[a.l], ar = bi[a.r];
int bl = bi[b.l], br = bi[b.r];
if(al != bl)return a.l < b.l;
if(ar != br)return a.r < b.r;
return a.t < b.t;
}
void add(int x, int& res){
if(cnt[x] == 0)res ++ ;
cnt[x] ++ ;
}
void del(int x, int& res){
cnt[x] -- ;
if(cnt[x] == 0)res -- ;
}
int mq = 0,mc = 0;
int ans[mxlen];
inline void write(int res){
if(res<0){
putchar('-');
res=-res;
}
if(res>9)
write(res/10);
putchar(res%10+'0');
}
void modui(){
        for(int i = 1; i <= n; ++ i){
    bi[i] = (i - 1) / block;
    }
    sort(q + 1, q + 1 + mq, cmp);
    for(register int k = 1, i = 0, j = 1, t = 0, res = 0; k <= mq; ++ k){
        int id = q[k].id, l = q[k].l, r = q[k].r, tim = q[k].t;
        while(i < r)res += ++ cnt[a[ ++ i]] == 1;
    while(i > r)res -= -- cnt[a[i -- ]] == 0;
    while(j < l)res -= -- cnt[a[j ++ ]] == 0;
    while(j > l)res += ++ cnt[a[ -- j]] == 1;
    //再处理y轴
    while(t < tim){
    t ++ ;
    if(c[t].pos >= j && c[t].pos <= i){
    del(a[c[t].pos], res);
    add(c[t].col, res);
    //res -= !--cnt[w[c[t].pos]] - !cnt[c[t].col]++;
    }
    swap(a[c[t].pos], c[t].col);
    }
    while(t > tim){
    if(c[t].pos >= j && c[t].pos <= i){
    del(a[c[t].pos], res);
    add(c[t].col, res);
    //res -= !--cnt[w[c[t].pos]] - !cnt[c[t].col]++;
    }
    swap(a[c[t].pos], c[t].col);
    t -- ;
    }
    ans[id] = res;
    }

    for(int i=1;i<=mq;i++){
        write(ans[i]), puts("");
    }
}
void solve_large(int op){
    
    if(op==1){
        int L,R;
        cin>>L>>R;
        q[++mq] = (Query){mq,L,R,mc};        
    }else if(op==2){
        int P,V;
        cin>>P>>V;
        c[++mc] = (Modify){P,V};
    }else {
        modui();
        memset(cnt,0,sizeof(cnt));
        mq = 0;
        mc = 0;
        int P,V;
        cin>>P>>V;
        n++;
       a.insert(a.begin()+P,V);
    }
}
void solve(int op){
    if(n>1e4){
        solve_large(op);
        return ;
    }
    if(op==1){
        int L,R;
        cin>>L>>R;
        int ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i=L;i<=R;i++){
            if(!vis[a[i]]){
                ans++;
                vis[a[i]]=1;
            }
        }
        cout<<ans<<endl;
    }else if(op==2){
        int P,V;
        cin>>P>>V;
        a[P] = V;
    }else {
        int P,V;
        cin>>P>>V;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while(T--){
        int m;
        cin>>n>>m;
        int x;
        a.push_back(0);
        for(int i=1;i<=n;i++){
            cin>>x;
            a.push_back(x);
        }
        int op;
        while(m--){
            cin>>op;
            solve(op);
        }

        if(n>1e4&&op!=3) modui();

    }
    return 0;
}
