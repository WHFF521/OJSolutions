#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Trie{
    int cnt;
    Trie* next[26];
    bool flag;
    Trie(){
        cnt = 0;
        flag = false;
        for(int i=0;i<26;i++) next[i] = NULL;
    }
};

void insert(Trie *root,string s){
    int len = s.length();
    Trie *p = root;
    for(int i=0;i<len;i++){
        int x = s[i]-'a';
        if(p->next[x]==NULL) p->next[x] = new Trie();
        p = p->next[x];
        p->cnt++;
    }
    p->flag = true;
}

int find(Trie *root,string s){
    int len = s.length();
    Trie *p = root;
    for(int i=0;i<len;i++){
        int x = s[i]-'a';
        if(p->next[x]==NULL) return 0;
        p = p->next[x];
    }
    return p->cnt;
}

int main(){
    Trie *root = new Trie();
    string s;
    while(getline(cin,s)){
        if(s=="") break;
        insert(root,s);
    }
    while(cin>>s){
        cout<<find(root,s)<<endl;
    }
    return 0;
}