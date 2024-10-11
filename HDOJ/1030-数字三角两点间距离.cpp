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

int main(){
    ll n,m;
    while(scanf("%lld%lld",&m,&n)!=EOF){
        // 求n和m在水平方向上的层数
        ll levelN = ceil(sqrt(n));
        ll levelM = ceil(sqrt(m));
        // 求n和m在左斜水平方向上的位置，n减去levelN-1层的数字，再除以2，+1为了向上取整
        ll leftLevelN = (n-(levelN-1)*(levelN-1)+1)/2;
        ll leftLevelM = (m-(levelM-1)*(levelM-1)+1)/2;
        // 求n和m在右斜水平方向上的位置，n所在水平层最后一个数字减去n再+1得到n到右边的距离，再除以2，+1为了向上取整
        // 除以2是因为2个数为一层
        ll rightLevelN = (levelN*levelN-n+1+1)/2;
        ll rightLevelM = (levelM*levelM-m+1+1)/2;
        ll ans = abs(levelN-levelM)+abs(leftLevelN-leftLevelM)+abs(rightLevelN-rightLevelM);
        printf("%lld\n",ans);
    }
    return 0;
}