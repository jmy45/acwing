//810ms
#include<iostream>
using namespace std;
typedef long long LL;
const int N=200010;
int m,p,a;
int arr[N];
struct SegTree{
    int maxval,l,r,cnt;
    SegTree *left,*right;
    SegTree(int l,int r):l(l),r(r),maxval(0),cnt(0),left(nullptr),right(nullptr){}
};
void add(SegTree * root,int x){
    int l=root->l,r=root->r;
    if (root->cnt==r-l+1){
        return;
    }
    if (x<=l&&r<=x){
        root->maxval=arr[x];
        root->cnt=1;
        return ;
    }
    int md=l+r>>1;
    if (root->left==nullptr) root->left=new SegTree(l,md);
    if (root->right==nullptr) root->right=new SegTree(md+1,r);
    if (x<=md) add(root->left,x);
    if (md<x) add(root->right,x);
    root->maxval=max(root->left->maxval,root->right->maxval);
    root->cnt=root->left->cnt+root->right->cnt;
}
int query(SegTree *root,int t){
    int l=root->l,r=root->r;
    if (root->cnt==t){
        return root->maxval;
    }
    int md=l+r>>1;
    int rcnt=root->right->cnt;
    int ans=query(root->right,min(t,rcnt));
    if (rcnt<t) 
        ans=max(ans,query(root->left,t-rcnt));
    return ans;
}
int main(){
    scanf("%d%d",&m,&p);
    SegTree *root=new SegTree(1,2e9);
    int idx=1;
    char ch;
    int t;
    while (m--){
        scanf("%c",&ch);
        scanf("%c%d",&ch,&t);
        if (ch=='A'){
            arr[idx]=((LL)t+a)%p;
            add(root,idx++);
        }
        else{
            a=query(root,t);
            printf("%d\n",a);
        }
    }
    return 0;
}