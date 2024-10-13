#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int n;

int main(){
    while(scanf("%d",&n)==1){
        if(n==0) break;
        vector<int> a(n);
        bool flag = false;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=a[0]) flag = true;
        }
        
        int cnt = 0;
        while(flag){
            int temp = a[n-1]/2;
            bool same_flag = true;
            for(int i=0;i<n;i++){
                int x = a[i]/2;
                a[i] = x+temp;
                if(a[i]%2==1) a[i]++;
                temp = x;
                if(a[i]!=a[0]) same_flag = false;
            }
            cnt++;
            if(same_flag) flag = false;
        }
        printf("%d %d\n",cnt,a[0]);
    }
    return 0;
}