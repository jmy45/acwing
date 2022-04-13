#include<iostream>
#include<vector>
using namespace std;
int A,B;
const int N=31;
int f[N][N];
void init(){
    for (int i=0;i<=9;i++)
        f[1][i]=1;
    for (int i=2;i<N;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++)
                if (abs(j-k)>=2)
                    f[i][j]+=f[i-1][k];
}
int dp(int n){
    if (!n) return 0;
    vector<int> nums;
    while (n) nums.push_back(n%10),n/=10;
    int ans=0;
    int last=0;
    for (int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for (int j=0;j<x;j++){
            if (i==nums.size()-1){
                if (j==0)
                {
                    for (int k=nums.size()-2;k>=0;k--)
                        for (int l=1;l<=9;l++)
                            ans+=f[k+1][l];
                }
                else 
                    ans+=f[i+1][j];
            }
            else if (abs(j-last)>=2)
                ans+=f[i+1][j];    
        }            
        if (i!=nums.size()-1&&abs(x-last)<2) break;
        last=x;
        if (!i) ans++;
    }
    return ans;
}
int main(){
    init();
    cin>>A>>B;
    cout<<dp(B)-dp(A-1)<<endl;
    return 0;
}