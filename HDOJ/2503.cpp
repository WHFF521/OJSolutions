#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int a,b,c,d;
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        int Numerator = a*d+b*c;
        int Denominator = b*d;
        int divisor = gcd(Numerator,Denominator);
        cout<<Numerator/divisor<<" "<<Denominator/divisor<<endl;
    }
    return 0;
}