#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll partition(vector<ll>&a , ll start, ll end)
{
	
	ll pivot = a[end];
	ll pindex = start;
	
	for(ll i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			//swap a[pindex] and a[i]
			swap(a[pindex],a[i]);
			
			//Increment pindex
			pindex++;
		}
	}
	swap(a[pindex],a[end]);
	return pindex;
}
ll kthsmallest(vector<ll>&a,ll start, ll end,ll k)
{
	if(start>end || k>end+1 || k<start+1)
		return -1;
	
	ll pos = partition(a,start,end);
	
	if(pos+1==k)
		return a[pos];
		
	//Left sub array 
	if(pos+1>k)
		return kthsmallest(a,start,pos-1,k);
	else
		return kthsmallest(a,pos+1,end,k); //Right sub array
}

int main()
{
	ll n,i,k;
	
	cin>>n>>k;
	vector<ll> a(n);
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cout<<kthsmallest(a,0,n-1,k);
	
	return 0;
}
