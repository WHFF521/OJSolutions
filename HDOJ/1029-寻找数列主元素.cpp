#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        ll ans = 0;
        ll cnt = 0;
        ll x;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(cnt==0){
                ans = x;
                cnt = 1;
            }else{
                if(ans==x){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}