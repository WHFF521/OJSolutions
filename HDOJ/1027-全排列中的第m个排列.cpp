#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int n,m;
int a[1005];
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++) a[i] = i;
        for(int i=1;i<m;i++) next_permutation(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(i==n) printf("%d\n",a[i]);
            else printf("%d ",a[i]);
        }
    }
    return 0;
}