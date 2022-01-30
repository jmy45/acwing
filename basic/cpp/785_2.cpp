//three-way qsort  250ms
#include<iostream>
using namespace std;
const int N=100010;
int q[N];
void qsort(int arr[],int l,int r)
{
	if(l>=r)	return ;
	int rnd_idx = rand() % (r - l + 1) + l;
    swap(q[l], q[rnd_idx]);
	int v=arr[l];
	int lt=l;
	int gt=r+1;
	int i=l+1;
	while(i<gt)
	{
		if(arr[i]<v)
		//l+1--lt指向<v,lt--i-1指向==v,gt--r指向>v
		{
            swap(arr[i],arr[lt+1]);
		    lt++;
		    i++;
        }
		else if(arr[i]>v)
		{
			swap(arr[i],arr[gt-1]);
			gt--;
		}
		else	i++;
	}
	swap(arr[l],arr[lt]);
	qsort(arr,l,lt-1);
	qsort(arr,gt,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&q[i]);
    qsort(q,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",q[i]);
    return 0;
 }