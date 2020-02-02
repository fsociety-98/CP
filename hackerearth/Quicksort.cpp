#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll partition(vector<ll>& a,ll start,ll end)
{
	ll pivot = a[end];
	ll pindex = start;
	ll temp;
	
	for(ll i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			//swap a[i] and a[pindex]
			temp = a[i];
			a[i] = a[pindex];
			a[pindex] = temp;
			
			//Increment pindex
			pindex++;
		}
	}
	
	//Swap a[pindex] and a[end]
	temp = a[pindex];
	a[pindex] = pivot;
	a[end] = temp;
	
	return pindex; 
}
void quicksort(vector<ll>& a,ll start,ll end)
{
	if(start>=end)
		return;
	ll p = partition(a,start,end);
	quicksort(a,start,p-1);
	quicksort(a,p+1,end);
}
int main()
{
	ll n,i;
	cin>>n;
	
	vector<ll> a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
		
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)	
		cout<<a[i]<<" ";
	return 0;
}
