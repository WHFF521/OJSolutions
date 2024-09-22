#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int a[100];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n,k;
        scanf("%d%d", &n,&k);
        int remain = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(a[i]>=k) remain +=a[i];
            else if(a[i]==0){
                if(remain){
                    remain--;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}