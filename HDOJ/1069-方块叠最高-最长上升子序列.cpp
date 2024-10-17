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
int n;
struct node{
    int length,width,height;
    bool operator<(const node &a)const{
        if(length==a.length) return width<a.width;
        return length<a.length;
    }
};

int main(){
    int Case = 0;
    vector<node> v;
    while(scanf("%d",&n)&&n){
        for(int i=1,x,y,z;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            v.push_back({x,y,z});
            v.push_back({x,z,y});
            v.push_back({y,x,z});
            v.push_back({y,z,x});
            v.push_back({z,x,y});
            v.push_back({z,y,x});
        }
        sort(v.begin(),v.end());
        vector<int> dp(v.size());
        int ans = 0;
        for(int i=0;i<v.size();i++){
            dp[i] = v[i].height;
            int len = v[i].length;
            int wid = v[i].width;
            for(int j=0;j<i;j++){
                if(v[j].length<len&&v[j].width<wid){
                    dp[i] = max(dp[i],dp[j]+v[i].height);
                }
            }
            ans = max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++Case,ans);
        v.clear();
    }
    return 0;
}