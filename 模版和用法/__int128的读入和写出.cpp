#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
void read(__int128 &x){
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9'){
        x = x*10+c-'0';
        c = getchar();
    }
}

void print(__int128 x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        __int128 a,b,c,d;
        read(a);
        read(b);
        read(c);
        read(d);
        print(a+b+c+d);
        putchar('\n');
    }
    return 0;
}