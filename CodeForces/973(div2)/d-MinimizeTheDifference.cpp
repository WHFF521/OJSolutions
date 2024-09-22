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
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        ll ma = 0;
        ll mi = 1e18;
        ll sum = 0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            mi = min(mi,sum/i);
        }
        sum = 0;
        for(int i=n;i>=1;i--){
            sum+=a[i];
            ma = max(ma,(sum+n-i)/(n-i+1));
        }
        printf("%lld\n",ma-mi);
    }
    return 0;
}