#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#define ll long long
using namespace std;
vector<ll> a;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        a.clear();
        int n;
        scanf("%d", &n);
        ll x;
        for(int i=0; i<n; i++){
            scanf("%lld", &x);
            a.push_back(x);
        }
        if(n%2==0){
            ll ans = 1;
            for(int i=0;i<n;i++){
                if(i%2==1){
                    ans = max(ans, a[i]-a[i-1]);
                }
            }
            printf("%lld\n", ans);
            continue;
        }else {
            ll ans = 1e18+5;;
            for(int pos = 0;pos<n;pos++){
                if(pos==1||pos==n-2) continue;
                ll tmp = 1;
                int mod = 1;
                for(int i=0;i<n;i++){
                    if(i==pos){
                        mod = 0;
                        continue;
                    }
                    if(i%2==mod){
                        tmp = max(tmp, a[i]-a[i-1]);
                    }
                }
                ans = min(ans,tmp);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}