#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define ll long long
using namespace std;
const int mod = 9973;

// 扩展欧几里得
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t-a/b*y;
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        // n = A%9973,求(A/B)%9973
        ll B,x,y,n;
        cin>>n>>B;
        exgcd(B,mod,x,y);
        x = (x%mod+mod)%mod;
        cout<<x*n%mod<<endl;
    }
    return 0;
}