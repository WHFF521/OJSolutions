#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#define ll long long
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n,k;
        scanf("%d %d", &n, &k);
        if(n==1&&k==1){
            printf("1\n");
            printf("1\n");
            continue;
        }
        if(k==1||k==n){
            printf("-1\n");
            continue;
        }
        if(k%2==0){
            printf("3\n");
            printf("1 %d %d\n",k,k+1);
        }
        else {
            printf("3\n");
            printf("1 %d %d\n",k-1,k+2);
        }
        
    }
    return 0;
}