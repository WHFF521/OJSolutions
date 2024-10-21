#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
typedef long long LL;
int n,m,mo,a[maxn];
struct tree
{
	int l,r;
	LL sum,lazy1,lazy2;
}t[4*maxn];
void build(int x,int l,int r)
{
	t[x].l=l;t[x].r=r;t[x].lazy1=1;
	if(l==r)
	{
		t[x].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	t[x].sum=(t[2*x].sum+t[2*x+1].sum)%mo;
}
void update(int x)
{
	LL mul=t[x].lazy1;
	LL add=t[x].lazy2;
	t[2*x].sum=(mul*t[2*x].sum%mo+add*(t[2*x].r-t[2*x].l+1)%mo)%mo;
	t[2*x+1].sum=(mul*t[2*x+1].sum%mo+add*(t[2*x+1].r-t[2*x+1].l+1)%mo)%mo;
	(t[2*x].lazy1*=mul)%=mo;
	(t[2*x+1].lazy1*=mul)%=mo;
	(t[2*x].lazy2*=mul)%=mo;
	(t[2*x+1].lazy2*=mul)%=mo;
	(t[2*x].lazy2+=add)%=mo;
	(t[2*x+1].lazy2+=add)%=mo;
	t[x].lazy1=1;
	t[x].lazy2=0;
}
void change(int x,int l,int r,int z,int op)
{
	if(t[x].l==l&&t[x].r==r)
	{
		if(op==2)
		{
			(t[x].sum+=(LL)z*(r-l+1))%=mo;
			(t[x].lazy2+=z)%=mo;
		}
		else
		{
			t[x].sum=(t[x].sum*(LL)z)%mo;
			(t[x].lazy1*=(LL)z)%=mo;
			(t[x].lazy2*=(LL)z)%=mo;
		}
		return  ;
	}
	if(t[x].lazy1!=1||t[x].lazy2) update(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l>mid) change(2*x+1,l,r,z,op);
	else if(r<=mid) change(2*x,l,r,z,op);
	else
	{
		change(2*x,l,mid,z,op);
		change(2*x+1,mid+1,r,z,op);
	}
	t[x].sum=(t[2*x].sum+t[2*x+1].sum)%mo;
}
int query(int x,int l,int r)
{
	if(t[x].l==l&&t[x].r==r) return t[x].sum;
	if(t[x].lazy1!=1||t[x].lazy2) update(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l>mid) return query(2*x+1,l,r);
	else if(r<=mid) return query(2*x,l,r);
	else return (query(2*x,l,mid)+query(2*x+1,mid+1,r))%mo;
}
	
int main()
{
	scanf("%d%d%d",&n,&m,&mo);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,k;
		scanf("%d%d%d",&op,&x,&y);
		if(op!=3)
		{
			scanf("%d",&k);
			change(1,x,y,k,op);
		}
		else
		{
		   printf("%d\n",query(1,x,y));
		}
	}
	return 0;
}