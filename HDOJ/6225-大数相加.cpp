#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

string sum(string s1, string s2)
{
	if(s1.length() < s2.length())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int i, j;
	for(i = s1.length() - 1, j = s2.length() - 1; i >= 0; i--, j--) {
		s1[i] = char(s1[i] + (j >= 0 ? s2[j] - '0' : 0));
		if(s1[i] - '0' >= 10){
			s1[i] = char((s1[i] - '0') % 10 +'0');
			if(i)	s1[i-1]++;
			else
				s1 = '1' + s1;
		}
	}
	return s1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        string res = sum(sum(a,b),sum(c,d));
        cout<<res<<endl;
    }
    return 0;
}