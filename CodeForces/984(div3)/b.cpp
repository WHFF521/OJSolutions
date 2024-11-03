#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
const int mxlen = 2e5+5;
bool vis[mxlen];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(vis, 0, sizeof(vis));
        int n,k;
        scanf("%d %d", &n, &k);
        int x,y;
        map<int,ll> m;
        vector<int> br;
        for(int i=1;i<=k;i++){
            scanf("%d%d", &x, &y);
            if(!vis[x]){
                m[x] = y;
                vis[x] = true;
                br.push_back(x);
            }else m[x]+=y;
        }
        vector<ll> v;
        for(int i=0;i<br.size();i++){
            v.push_back(m[br[i]]);
        }
        sort(v.begin(), v.end(), greater<ll>());
        ll ans = 0;
        for(int i=0;i<n&&i<k&&i<v.size();i++){
            ans+=v[i];
        }
        // cout<<"ans: "<<ans<<endl;
        printf("%lld\n", ans);
    }
    return 0;
}