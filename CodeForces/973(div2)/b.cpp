#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const int mxlen = 2e5+10;
ll a[mxlen];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        ll ans = a[n-1]-a[n-2];
        for(int i=n-3;i>=0;i--){
            ans+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}