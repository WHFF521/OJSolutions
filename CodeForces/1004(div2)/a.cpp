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
        int x,y;
        scanf("%d%d",&x,&y);
        int remainder = (x-y+1)%9;
        if(remainder==0&&(x-y+1)/9>=0){
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}