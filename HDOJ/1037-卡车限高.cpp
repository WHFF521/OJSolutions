#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    double a,b,c;
    double height = 168;
    double d[3];
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        d[0] = a; d[1] = b; d[2] = c;
        bool flag = false; 
        for(int i=0;i<3;i++){
            if(d[i]<=height){
                flag = true;
                printf("CRASH %.0lf\n",d[i]);
                break;
            }
        }
        if(!flag) printf("NO CRASH\n");
    }
    return 0;
}