#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
        int Y,N;
        cin>>Y>>N;
        while(N){
            if(Y%400==0||(Y%4==0&&Y%100!=0)){
                N--;
            }
            Y++;
        }
        cout<<Y-1<<endl;
    }
    
    return 0;
}