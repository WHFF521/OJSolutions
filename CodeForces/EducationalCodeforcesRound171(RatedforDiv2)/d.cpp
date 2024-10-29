// test 6 TLE
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
const int mxlen = 1e6+5;
int n;
int a[mxlen];
ll sum[mxlen];
ll ans[mxlen];
struct Query
{
    ll id,l,r;
}q[mxlen];
int block;
ll get_block(ll x){
    return x/block;
}
bool cmp(const Query &x,const Query &y){
    ll a = get_block(x.l);
    ll b = get_block(y.l);
    if(a!=b) return a<b;
    return x.r<y.r;
}

pair<ll,ll> change(ll x){
    ll l = 1,r = n;
    while(l<r){
        ll mid = (l+r)/2;
        if(mid*(2*n-mid+1)/2<x) l=mid+1;
        else r = mid;
    }
    l--;
    ll pre = l*(2*n-l+1)/2;
    r = x-pre+l;
    return make_pair(l+1,r);
}
void add(ll x,ll &res){
    pair<ll,ll> p = change(x);
    ll l = p.first;
    ll r = p.second;
    res+=sum[r]-sum[l-1];
}
void del(ll x,ll &res){
    pair<ll,ll> p = change(x);
    ll l = p.first;
    ll r = p.second;
    res-=sum[r]-sum[l-1];
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    int m;
    scanf("%d", &m);
    block = sqrt(n);
    for(int i=0;i<m;i++){
        scanf("%lld%lld", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q,q+m,cmp);
    ll res = 0;
    for(ll k=0,i=0,j=1;k<m;++k){
        ll id = q[k].id,l = q[k].l,r = q[k].r;
        while(i<r) add(++i,res);
        while(i>r) del(i--,res);
        while(j<l) del(j++,res);
        while(j>l) add(--j,res);
        ans[q[k].id] = res;
    }
    for(int i=0;i<m;i++){
        printf("%lld\n", ans[i]);
    }

    return 0;
}