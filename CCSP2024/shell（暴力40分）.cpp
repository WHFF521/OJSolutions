#include<bits/stdc++.h>
using namespace std;
const int mxlen = 1e5+1e4+15;
int n;

int a[mxlen];

bool vis[mxlen*2];
int cnt[mxlen];
int pre_l,pre_r,pre_ans;
void solve_large(int op){
    
    if(op==1){
        int L,R;
        cin>>L>>R;
        
        while(pre_l<L){
            if(!cnt[a[pre_l]]) {pre_l++;continue;}
            cnt[a[pre_l]]--;
            if(!cnt[a[pre_l]]) pre_ans--;
            pre_l++;
        }        
        while(pre_l>L){
            pre_l--;
            if(!cnt[a[pre_l]]){
                pre_ans++;
                
            }
            cnt[a[pre_l]]++;
        }
        while(pre_r<R){
            pre_r++;
            if(!cnt[a[pre_r]]) {
                pre_ans++;
            }
            cnt[a[pre_r]]++;
        }
        while(pre_r>R){
            cnt[a[pre_r]]--;
            if(!cnt[a[pre_r]]){
                pre_ans--;
            }
            pre_r--;
        }
        cout<<pre_ans<<endl;
    }else if(op==2){
        int P,V;
        cin>>P>>V;
        a[P] = V;
    }else {
        int P,V;
        cin>>P>>V;
        n++;
        for(int i=n;i>P;i--) a[i] = a[i-1];
        a[P+1] = V;
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
        n++;
        for(int i=n;i>P;i--) a[i] = a[i-1];
        a[P+1] = V;
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
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int op;
        while(m--){
            cin>>op;
            solve(op);
        }

    }
    return 0;
}
