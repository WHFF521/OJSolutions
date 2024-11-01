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
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int x;
        int sum1 = 0;
        int sum2 = 0;
        int flag = 0;
        for(int i = 0; i < n*2; i++){
            cin >> x;
            sum1 += x;
            
            if(!flag) sum2 += x;
            else sum2 -= x;
            if(sum2>=n) flag = 1;
        }
        if(sum1%2) cout<<"1 ";
        else cout<<"0 ";
        cout<<sum2<<endl;
    }
    return 0;
}