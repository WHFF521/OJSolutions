#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100050;
struct tree
{
	int l,r;
	long long sum;
	long long lazy;
}t[4*maxn];
int n,m,a[maxn];

void build(int x,int l,int r)
{
	t[x].l=l;t[x].r=r;
	if(l==r)
	{
		t[x].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	t[x].sum=t[2*x].sum+t[2*x+1].sum;
}

void update(int x)
{
	t[2*x].sum+=(t[2*x].r-t[2*x].l+1)*t[x].lazy;
	t[2*x+1].sum+=(t[2*x+1].r-t[2*x+1].l+1)*t[x].lazy;
	t[2*x].lazy+=t[x].lazy;
	t[2*x+1].lazy+=t[x].lazy;
	t[x].lazy=0;
}

void change(int x,int l,int r,ll z)
{
	if(t[x].l==l&&t[x].r==r)
	{
		t[x].sum+=(t[x].r-t[x].l+1)*z;
		t[x].lazy+=z;
		return ;
	}
	if(t[x].lazy) update(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(r<=mid)
	{
		change(2*x,l,r,z);
	}
	else if(l>mid)
	{
		change(2*x+1,l,r,z);
	}
	else
	{
		change(2*x,l,mid,z);
		change(2*x+1,mid+1,r,z);
	}
	t[x].sum=t[2*x].sum+t[2*x+1].sum;
}

ll query(int x,int l,int r)
{
	if(t[x].l==l&&t[x].r==r)
	{
		return t[x].sum;
	}
	if(t[x].lazy) update(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(r<=mid)
	{
		return query(2*x,l,r);
	}
	else if(l>mid)
	{
		return query(2*x+1,l,r);
	}
	else 
	{
		return query(2*x,l,mid)+query(2*x+1,mid+1,r);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y,op;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			ll k;
			scanf("%lld",&k);
			change(1,x,y,k);
		}
		else if(op==2)
		{
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}