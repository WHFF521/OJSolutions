#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 2e5;

int n,m,k;
struct node{
    double value;
    int index;
}a[mxlen];
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            double x;
            for(int j=1;j<=m;j++){
                scanf("%lf",&x);
                a[j].value +=x;
                a[j].index = j;
            }
        }
        sort(a+1,a+m+1,[](node x,node y){
            if(x.value==y.value) return x.index<y.index;
            return x.value>y.value;
        });

        sort(a+1,a+k+1,[](node x,node y){
            return x.index>y.index;
        });
        for(int i=1;i<=k;i++){
            if(i==1) printf("%d",a[i].index);
            else printf(" %d",a[i].index);
        }
        printf("\n");
    }
    return 0;
}