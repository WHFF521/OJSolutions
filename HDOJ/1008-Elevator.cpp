#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int floor = 0;
        long long time = 0;
        for(int i=1;i<=n;i++){
            int target;
            scanf("%d",&target);
            if(target>floor){
                time += (target-floor)*6+5;
            }else {
                time += (floor-target)*4+5;
            }
            floor = target;
        }
        printf("%lld\n",time);
    }
    return 0;
}