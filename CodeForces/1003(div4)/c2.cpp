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

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        
        scanf("%d%d",&n,&m);
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        sort(b.begin(),b.end());
        a[0] = min(a[0],b[0]-a[0]);
        bool flag = false;
        for(int i=1;i<n;i++){
            auto it = lower_bound(b.begin(),b.end(),-1,[&](int x,int y){
                return x-a[i]< a[i-1];
            });
            if(it==b.end()){
                if(a[i]>=a[i-1]) continue;
                flag = true;
                break;
            }
            int c = *it;
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