//MLE
#include<iostream>
#include<vector>
using namespace std;

struct Trie {
    Trie* children[2];
}*r;
void insert(int x){
        Trie *root=r;
        for (int i=30;i>=0;i--){
            int y=x>>i&1;
            if (!root->children[y])
                root->children[y]=new Trie();
            root=root->children[y];
        }
}
int find(int e){
    Trie* p=r;
    int t=0;
    for (int i=30;i>=0;i--){
        int cur=e>>i&1;
        t<<=1;
        if (p->children[!cur]){
            p=p->children[!cur];
            t++;
        }
        else
            p=p->children[cur];           
    }
    return t;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    r=new Trie();
    int ans=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
        if (i){
            ans=max(ans,find(a[i]));
        }
    }
    cout<<ans<<endl;
    return 0;
}