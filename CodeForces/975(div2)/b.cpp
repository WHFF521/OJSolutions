#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 1e5+5;
int n,q;
ll a[mxlen];

int main(){
    int T;  
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        map<ll,ll>mp;
        for(int i=1;i<=n;i++){
            ll temp = (ll)(i-1)*(n-i)+n-1;
            mp[temp]++;
            if(i<n){
                temp = (ll)i*(n-i);
                mp[temp]+=a[i+1]-a[i]-1;
            }
        }
        ll x;
        for(int i=1;i<=q;i++){
            scanf("%lld",&x);
            printf("%lld ",mp[x]);
        }
        printf("\n");
    }
    return 0;
}