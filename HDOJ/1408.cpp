#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

int main(){
    double val,d;
    while(scanf("%lf%lf",&val,&d)!=EOF){
        int gap = 0;
        double water = val;
        for(int i=1;;i++){
            if(val<=0) break;
            val -=i*d;
            gap++;
        }
        gap--;
        cout<<gap+(int)ceil(water/d)<<endl;
    }
    return 0;
}