#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
// 不加这个string会CE。。。
#include<string>
using namespace std;

void add(vector<int> &A,vector<int> &B,vector<int> &C){
    int carry = 0;
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i<A.size()) carry += A[i];
        if(i<B.size()) carry += B[i];
        C.push_back(carry%10);
        carry /= 10;
    }
    if(carry) C.push_back(carry);
}
int main(){
    int T;
    cin >> T;
    string a,b;
    int cnt = 1;
    while(T--){
        cin >> a >> b;
        vector<int> A,B,C;
        for(int i=a.size()-1;i>=0;i--){
            A.push_back(a[i]-'0');
        }
        for(int i=b.size()-1;i>=0;i--){
            B.push_back(b[i]-'0');
        }
        add(A,B,C);
        cout<< "Case "<<cnt++<<":"<<endl;
        cout<<a<<" + "<<b<<" = ";
        for(int i=C.size()-1;i>=0;i--){
            cout<<C[i];
        }
        if(T)cout<<endl<<endl;
    }
    return 0;
}