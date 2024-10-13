#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 1005;

int catalan[105][mxlen];
// catalan[i][j] stores the j-th digit of the i-th catalan number
// h(n) = (4n-2)*h(n-1)/(n+1)
void pre_work(){
    catalan[1][0] = 1;
    for(int i=2;i<=100;i++){
        int tmp = 0 ;
        int j = 0;
        for(j=0;j<mxlen;j++){
            tmp+=catalan[i-1][j]*(4*i-2);
            catalan[i][j] = tmp%10;
            tmp/=10;
        }
        // mxlen is big enough, so tmp will be 0 after the loop
        j=mxlen-1;
        while(catalan[i][j]==0) j--;
        while(j>=0){
            tmp = tmp*10+catalan[i][j];
            catalan[i][j--] = tmp/(i+1);  
            if(tmp>=i+1) tmp%=(i+1);
        }
        // Catalan number is a integer, so remain is 0
    }
}
int main(){
    pre_work();
    int n;
    while(scanf("%d",&n)!=EOF){
        int i = mxlen-1;
        while(catalan[n][i]==0) i--;
        while(i>=0) printf("%d",catalan[n][i--]);
        printf("\n");
    }
}