#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
ll a[25];
void init(){
    a[2] = 1;
    a[3] = 2;
    for(int i=4;i<=20;i++){
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}