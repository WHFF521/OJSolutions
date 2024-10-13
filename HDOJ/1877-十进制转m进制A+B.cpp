#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const int mxlen = 1005;
int m;
ll a,b;
void changeM(ll x){
    if(x==0){
        return;
    }
    changeM(x/m);
    printf("%lld",x%m);
}
int main(){
    while(scanf("%d",&m)&&m){
        scanf("%lld%lld",&a,&b);
        changeM(a+b);
        if(a+b==0){
            printf("0");
        }
        printf("\n");
    }

    return 0;
}