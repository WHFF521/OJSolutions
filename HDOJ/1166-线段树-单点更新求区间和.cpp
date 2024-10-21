#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen =5e4+5;
int n;
int t[4*mxlen];
void build(int k,int l,int r){
    if(l==r){
        scanf("%d",&t[k]);
        return ;
    }
    int mid = (l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    t[k] = t[k<<1]+t[k<<1|1];
}

int query(int k,int l,int r,int ll,int rr){
    if(l>=ll&&r<=rr){
        return t[k];
    }
    int mid = (l+r)>>1;
    int ans = 0;
    if(ll<=mid) ans+=query(k<<1,l,mid,ll,rr);
    if(rr>mid) ans+=query(k<<1|1,mid+1,r,ll,rr);
    return ans;
}

void Add(int k,int l,int r,int pos,int val){
    if(l==r){
        t[k]+=val;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos<=mid) Add(k<<1,l,mid,pos,val);
    else Add(k<<1|1,mid+1,r,pos,val);

    t[k] = t[k<<1]+t[k<<1|1];
}

int main(){
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
        cin>>n;
        build(1,1,n);
        printf("Case %d:\n",++Case);
        char s[10];
        int a,b;
        while(scanf("%s",s)&&s[0]!='E'){
            scanf("%d%d",&a,&b);
            if(s[0]=='Q'){
                printf("%d\n",query(1,1,n,a,b));
            }else if(s[0]=='A'){
                Add(1,1,n,a,b);
            }else if(s[0]=='S'){
                Add(1,1,n,a,-b);
            }
        }
    }
    return 0;
}
