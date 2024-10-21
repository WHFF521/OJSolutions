#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mod = 10007;
const int mxlen = 1e5+5;
int t[4*mxlen];
bool flag[4*mxlen];
int n,m;

void Union(int k){
    int l = k<<1,r = k<<1|1;
    if(!flag[l]||!flag[r]) flag[k] = 0;
    else if(t[l]!=t[r]) flag[k] = 0;
    else t[k] = t[l],flag[k] = 1;
}

void pushdown(int k){
    if(flag[k]){
        flag[k<<1] = flag[k<<1|1] = 1;
        t[k<<1] = t[k<<1|1] = t[k];
        flag[k] = 0;
    }
}
void update(int k,int l_now,int r_now,int l_need,int r_need,int val,int type){
    if(l_now>=l_need&&r_now<=r_need&&flag[k]){
        if(type==1) t[k]=(t[k]+val)%mod;
        else if(type==2) t[k] = (t[k]*val)%mod;
        else t[k] = val;
        return ;
    }
    pushdown(k);
    int mid = (l_now+r_now)>>1;
    if(l_need<=mid) update(k<<1,l_now,mid,l_need,r_need,val,type);
    if(r_need>mid) update(k<<1|1,mid+1,r_now,l_need,r_need,val,type);
    Union(k);
}

int query(int k,int l_now,int r_now,int l_need,int r_need,int val){
    if(flag[k]&&l_now>=l_need&&r_now<=r_need){
        int ans = 1;
        for(int i=1;i<=val;i++) ans = (ans*t[k])%mod;
        ans=(ans*(r_now-l_now+1))%mod;
        return ans;
    }
    pushdown(k);
    int mid = (l_now+r_now)>>1;
    int ans = 0;
    if(l_need<=mid) ans = (ans+query(k<<1,l_now,mid,l_need,r_need,val))%mod;
    if(r_need>mid) ans = (ans+query(k<<1|1,mid+1,r_now,l_need,r_need,val))%mod;
    return ans%mod;
}

// 题目会有将一段区间变成同一个数的操作
// flag数组用来标记当前区间是否是同一个数
int main(){
    while(scanf("%d%d",&n,&m)&&(n||m)){
        memset(t,0,sizeof(t));
        memset(flag,1,sizeof(flag));
        int type,x,y,c;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&type,&x,&y,&c);
            if(type!=4) update(1,1,n,x,y,c,type);
            else printf("%d\n",query(1,1,n,x,y,c));
        }
    }
    return 0;
}