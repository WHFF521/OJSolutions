#include<iostream>
#include<map>
#include<vector>
#include<string>
#define ll long long
using namespace std;

void work(string s){
    vector<string> v;

    map<char,char>mp;
    int n;
    cin>>n;
    string temp="";
    getline(cin,temp);
    for(int i=0;i<n;i++){
        getline(cin,temp);
        mp[temp[1]]=temp[2];
    }
    int m;
    cin>>m;
    temp = s;
    map<string,int> mps;
    mps[temp] = 1;
    v.push_back(temp);
    while(1){
        for(int i=0;i<temp.length();i++){
            if(mp[temp[i]]){
                temp[i] = mp[temp[i]];
            }
        }
        if(mps[temp]==1){
            break;
        }
        v.push_back(temp);
        mps[temp] = 1;
    }
    int pos = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==temp){
            pos = i;
            break;
        }
    }
    int len = v.size();
    int loop = len - pos;
    
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        if(k<pos){
            cout<<v[k]<<endl;
        }else{
            cout<<v[pos+(k-pos)%loop]<<endl;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    work(s);
    return 0;
}