#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int n;
int main(){
    int T;
    cin >> T;
    int cnt = 1;
    while (T--)
    {
        cin >> n;
        int sum = 0;
        int max_sum = -1001;
        // 答案的start要单独记录
        int start = 1,ans_start = 1;
        int ans_end = 1;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            sum += a[i];
            if(sum > max_sum){
                max_sum = sum;
                ans_start = start;
                ans_end = i;
            }
            if(sum < 0 ){
                sum = 0;
                start = i+1;
            }
        }
        cout << "Case "<<cnt++<<":"<<endl;
        cout << max_sum << " " << ans_start << " " << ans_end << endl;
        if(T)cout<<endl;
    }
    
    return 0;
}