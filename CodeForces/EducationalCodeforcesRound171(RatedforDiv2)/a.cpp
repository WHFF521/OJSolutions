#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int X, Y, K;
        scanf("%d%d%d", &X, &Y, &K);
        int len = min(X,Y);
        printf("0 0 %d %d\n",len,len);
        printf("0 %d %d 0\n",len,len);
    }
    return 0;
}