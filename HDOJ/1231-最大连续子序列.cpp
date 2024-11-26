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

void solve(int len){
    vector<int> a(len);
    for(int i=0;i<len;i++){
        scanf("%d",&a[i]);
    }
    int sum = 0;
    int max_sum = -1;
    int start = 0;
    int end = 0;
    int temp_start = 0;
    for(int i=0;i<len;i++){
        sum+=a[i];
        if(sum>max_sum){
            max_sum = sum;
            start = temp_start;
            end = i;
        }
        if(sum<0){
            sum = 0;
            temp_start = i+1;
        }
    }
    if(max_sum<0){
        printf("0 %d %d\n",a[0],a[len-1]);
    }else{
        printf("%d %d %d\n",max_sum,a[start],a[end]);
    }
}
int main(){
    int k;
    while(scanf("%d",&k)&&k){
        solve(k);
    }
    return 0;
}