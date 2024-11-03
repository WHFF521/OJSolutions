#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#define ll long long
using namespace std;


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        vector<int> v;
        int x;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            v.push_back(x);
        }
        bool flag = false;
        for(int i=1;i<n;i++){
            int diff = abs(v[i]-v[i-1]);
            if(diff!=5&&diff!=7){
                flag = true;
                break;
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}