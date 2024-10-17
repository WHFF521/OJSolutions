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
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF){
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x3>x4) swap(x3,x4);
        if(y3>y4) swap(y3,y4);
        if(x1>=x4||x2<=x3||y1>=y4||y2<=y3){
            printf("0.00\n");
        }else{
            double x = min(x2,x4)-max(x1,x3);
            double y = min(y2,y4)-max(y1,y3);
            printf("%.2f\n",x*y);
        }
    }
    return 0;
}