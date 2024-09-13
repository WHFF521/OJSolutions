#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    double e = 0;
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    for(int i=0;i<=9;i++){
        double t = 1;
        for(int j=1;j<=i;j++){
            t *= j;
        }
        e += 1.0/t;
        if(i<2) printf("%d %d\n",i,(int)e);
        else if(i==2) printf("%d %.1f\n",i,e);
        else if(i>2) printf("%d %.9f\n",i,e);
    }
}