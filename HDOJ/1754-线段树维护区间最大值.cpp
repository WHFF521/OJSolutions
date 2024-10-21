#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 2e5+5;
int t[4*mxlen];
int n,m;

void build(int k,int l,int r){
    if(l==r){
        scanf("%d",&t[k]);
        return ;
    }
    int mid = (l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    t[k] = max(t[k<<1],t[k<<1|1]);
}

void update(int k,int l_now,int r_now,int pos,int val){
    if(l_now==r_now){
        t[k] = val;
        return ;
    }
    int mid = (l_now+r_now)>>1;
    if(pos<=mid) update(k<<1,l_now,mid,pos,val);
    else update(k<<1|1,mid+1,r_now,pos,val);
    t[k] = max(t[k<<1],t[k<<1|1]);
}
int query(int k,int l_now,int r_now,int l_need,int r_need){
    if(l_now>=l_need&&r_now<=r_need){
        return t[k];
    }
    int mid = (l_now+r_now)>>1;
    int ans = 0;
    if(l_need<=mid) ans = max(ans,query(k<<1,l_now,mid,l_need,r_need));
    if(r_need>mid) ans = max(ans,query(k<<1|1,mid+1,r_now,l_need,r_need));
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,1,n);
        char c;
        int a,b;
        while(m--){
            // 空格用来忽略所有空白字符
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='Q') printf("%d\n",query(1,1,n,a,b));
            else if(c=='U') update(1,1,n,a,b);
        }
    }
    return 0;
}