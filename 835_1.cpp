#include<bits/stdc++.h>
using namespace std;
class Trie{
    vector<Trie*> children;
    int n;
public:
    Trie():children(26,nullptr),n(0){

    };
    void Insert(string &str){
        Trie* root=this;
        for (char&ch:str){
            if (!root->children[ch-'a'])
                root->children[ch-'a']=new Trie();
            root=root->children[ch-'a'];
        }
        root->n++;
    }
    int Find(string &str){
        Trie* root=this;
        for (char&ch:str){
            if (!root->children[ch-'a'])
                return 0;
            root=root->children[ch-'a'];
        }
        return root->n;
    }
};
int N;
int main(){
    cin>>N;
    Trie* root=new Trie();
    for (int i=0;i<N;i++){
        char c;
        cin>>c;
        cin.get();
        string s;
        cin>>s;
        if (c=='I')
            root->Insert(s);
        else
            cout<<root->Find(s)<<endl;
    }
    return 0;
}