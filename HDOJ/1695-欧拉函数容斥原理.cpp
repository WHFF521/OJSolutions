#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define ll long long
using namespace std;
const int mxlen = 1e5+5;

vector<int> pri,pri_factors[mxlen];
bool not_prime[mxlen];
int phi[mxlen];
ll sum_phi[mxlen];
int pos_sum_phi;
// 求欧拉函数
void preEular(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        phi[i * pri_j] = phi[i] * pri_j;
        break;
      }
      phi[i * pri_j] = phi[i] * phi[pri_j];
    }
  }
}
int mx_d;
// 求取每个数的质因子
void get_prime_factors(int n){
    if(mx_d>n) return;
    for(int i=mx_d+1;i<=n;i++){
        for(int j=0;j<pri.size()&&pri[j]<=i;j++){
            if(i%pri[j]==0){
                pri_factors[i].push_back(pri[j]);
            }
        }
    }
    mx_d = n;
}
// 求1~n中与m互质的数的个数
int calc(int n,int m){
    int ans = 0;
    int size = pri_factors[m].size();
    // 二进制枚举，1表示选中，0表示不选中
    for(int i=1;i<(1<<size);i++){
        int cnt = 0;
        int tmp = 1;
        for(int j=0;j<size;j++){
            if(i&(1<<j)){
                cnt++;
                tmp*=pri_factors[m][j];
            }
        }
        // 奇数个质因子，加上；偶数个质因子，减去
        // 容斥原理，例：{2}+{3}-{2,3}，即2的倍数+3的倍数-2和3的倍数
        // {2}+{3}+{5}-{2,3}-{2,5}-{3,5}+{2,3,5}
        if(cnt&1) ans+=n/tmp;
        else ans-=n/tmp;
    }
    return n-ans;
}

int main(){
    int T;
    scanf("%d",&T);
    int Case = 0;
    preEular(mxlen-3);
    
    while(T--){
        Case++;
        printf("Case %d: ",Case);
        int a,b,c,d,k;
        // a到b中与c到d中GCD为k的数的个数
        //由于题目保证a=c=1，所以问题转化为求1到b/k中与1到d/k中互质的数的个数
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k>b||k>d||k==0){
            printf("0\n");
            continue;
        }
        if(b>d) swap(b,d);
        b/=k;d/=k;
        ll ans = 0;
        if(pos_sum_phi<b){
            for(int i=pos_sum_phi+1;i<=b;i++){
                sum_phi[i] = sum_phi[i-1]+phi[i];
            }
            pos_sum_phi = b;
        }
        ans = sum_phi[b];

        // 求一个数的质因子
        get_prime_factors(d);
        for(int i=b+1;i<=d;i++){
            ans+=calc(b,i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}