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
    int T;
    scanf("%d",&T);
    while(T--){
        int m,n;
        scanf("%d%d",&m,&n);
        int x;
        bool flagB = 0;
        bool flagM = 0;
        ll ans = 0;
        ll temp = 10000;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(i>m){
                ans+=temp;
                temp*=2;
                continue;
            }
            if(flagB){
                ans+=temp;
                temp*=2;
                continue;
            }
            if(x==1){
                flagB = 1;
            }
        }
        printf("%lld RMB\n",ans);
    }
    return 0;
}