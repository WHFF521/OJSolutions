#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int mxlen = 2e5+10;
long long a[mxlen];
int n;
long long sum;  
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
        sum = 0;
        for(int i = 1; i <=n; i++){
            scanf("%lld", &a[i]);
            sum+=a[i];
        }
        if(n<=2){
            printf("-1\n");
            continue;
        }
        sort(a+1,a+n+1);
        int pos = n/2+1;
        if(a[pos]*2*n<sum) {
            printf("0\n");
            continue;
        }
        long long ans = a[pos]*2*n - sum;
        printf("%lld\n",ans+1);

    }
    return 0;
}