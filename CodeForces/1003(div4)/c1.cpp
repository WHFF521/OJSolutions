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
const int mxlen = 2e5+5;
int n,m;
int a[mxlen];
int b[mxlen];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int c = b[1];
        a[1] = min(a[1],c-a[1]);
        bool flag = false;
        for(int i=2;i<=n;i++){
            int smaller = min(a[i],c-a[i]);
            int bigger = max(a[i],c-a[i]);
            if(smaller>=a[i-1]){
                a[i] = smaller;
            }else if(bigger>=a[i-1]){
                a[i] = bigger;
            }else {
                flag = true;
                break;
            }
        }
        if(flag){
            printf("NO\n");
        }else {
            printf("YES\n");
        }
    }
    return 0;
}