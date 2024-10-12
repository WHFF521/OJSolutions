#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
struct node{
    ll h;
    int w;
};
int n;

int main(){
    while(scanf("%d",&n)&&n!=0){
        // 双端队列声明单调栈
        deque<node> s;
        ll x;
        ll ans = 0;
        for(int i=1;i<=n+1;i++){
            // n+1的时候让栈内全部出栈
            if(i!=n+1) scanf("%lld",&x);
            else x = 0;
            int sum = 0;
            // 栈内元素从小到大排列，如果当前元素小于栈顶元素，出栈并计算面积
            // 面积是当前栈顶元素高度乘以左边比他高的元素个数加上右边比他高的元素个数
            // sum会加上每个弹出的元素的w，显然这个元素的高度大于x，sum即是新入栈元素的左边比他高的元素个数
            // 同时也保证了单调栈的性质
            while(!s.empty()&&s.back().h>x){
                node tmp = s.back();
                sum+=tmp.w;
                s.pop_back();
                ans = max(ans,tmp.h*sum);
            }
            s.push_back({x,sum+1});
        }
        printf("%lld\n",ans);
    }
    return 0;
}