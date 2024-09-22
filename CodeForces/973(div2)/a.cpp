#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int x,y;
        scanf("%d %d",&x,&y);
        int ans = 0;
        if(x>=y) ans = (n+y-1)/y;
        else ans = (n+x-1)/x;
        printf("%d\n",ans);

    }
    return 0;
}