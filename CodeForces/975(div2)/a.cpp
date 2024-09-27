#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 105;
int n;
struct node{
    int x,pos;
}a[mxlen];
bool cmp(node x,node y){
    return x.x>y.x;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int mx = 0;
        int mx_i = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].pos = i;
        }
        sort(a+1,a+n+1,cmp);
        int ans = 0;
        for(int i=1;i<=n;i++){
            int temp = a[i].x+(a[i].pos-1)/2+(n-a[i].pos)/2+1;
            
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}