#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

struct node{
    double x;
    double y;
};
bool cmp(node a,node b){
    return a.x/a.y>b.x/b.y;
}
int main(){
    int m,n;
    while(1){
        scanf("%d%d",&m,&n);
        if(m==-1&&n==-1) break;
        node a[1005];
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmp);
        double ans = 0;
        for(int i=0;i<n;i++){
            if(m>=a[i].y){
                ans += a[i].x;
                m -= a[i].y;
            }else {
                ans += a[i].x/a[i].y*m;
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}