#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
const int mxlen = 1e6+10;
int f[mxlen];

int main(){
    f[0]=7;f[1]=11;
    for(int i=2;i<=1000005;i++){
        f[i]=(f[i-1]+f[i-2])%3;
    }
    int x;
    while(scanf("%d",&x)!=EOF){
        if(f[x]%3==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}