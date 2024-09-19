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
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int right = n%10;
        int cycle = 2;
        int temp = (right*right)%10;
        while(temp!=right){
            temp = (temp*right)%10;
            if(temp!=right)cycle++;
        }
        
        int remain = n%cycle + cycle;
        temp = 1;
        while(remain--){
            temp = temp*right%10;
        }
        cout << temp << endl;
    }
    return 0;
}