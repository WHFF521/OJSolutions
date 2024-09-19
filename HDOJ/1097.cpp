#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
// almost the same as 1061-RightmostDigit.cpp
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        int n = a;
        int right = n%10;
        int cycle = 2;
        int temp = (right*right)%10;
        while(temp!=right){
            temp = (temp*right)%10;
            if(temp!=right)cycle++;
        }
        
        int remain = b%cycle + cycle;
        temp = 1;
        while(remain--){
            temp = temp*right%10;
        }
        cout << temp << endl;
    }
    return 0;
}