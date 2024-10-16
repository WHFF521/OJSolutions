#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;

int n;

struct node{
    int data;
    node *left,*right;
};
void insert_BST(node * &root,int x){
    if(root==NULL){
        root = new node;
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x<root->data) insert_BST(root->left,x);
    else insert_BST(root->right,x);
}
void delete_BST(node * &root){
    if(root==NULL) return;
    delete_BST(root->left);
    delete_BST(root->right);
    delete root;
}
bool BST_is_same(const node* const root1,const node* const root2){
    if(root1==NULL&&root2==NULL) return 1;
    if(root1==NULL||root2==NULL) return 0;
    if(root1->data!=root2->data) return 0;
    return BST_is_same(root1->left,root2->left)&&BST_is_same(root1->right,root2->right);
}

void build_BST(char *s,node * &root){
    int len = strlen(s);
    for(int i=0;i<len;i++){
        insert_BST(root,s[i]-'0');
    }
}

int main(){
    while(scanf("%d",&n)&&n){
        char s[10];
        scanf("%s",s);
        node *origin = NULL;
        build_BST(s,origin);
        while(n--){
            scanf("%s",s);
            node *test = NULL;
            build_BST(s,test);
            if(BST_is_same(origin,test)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            delete_BST(test);
        }
        delete_BST(origin);
    }
    return 0;
}