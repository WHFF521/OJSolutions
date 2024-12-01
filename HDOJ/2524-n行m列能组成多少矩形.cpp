#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        ll A = 0;
        for(int i=1;i<=n;i++){
            A+=i;
        }
        ll B = 0;
        for(int i=1;i<=m;i++){
            B+=i;
        }
        printf("%lld\n",A*B);
    }
    return 0;
}