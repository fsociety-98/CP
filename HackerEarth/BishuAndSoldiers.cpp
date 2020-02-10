#include<bits/stdc++.h>
using namespace std;

#define ll long long
int last_min;

void binary_search(vector<int>& nums,int key,int low,int high)
{
	if(low>high)
		return;
		
	int mid = (low+high)/2;
	
	if(nums[mid]==key)
		{
			last_min = mid;
			return;
		}
		
	if(key>nums[mid])
		{
			last_min = mid;
			binary_search(nums,key,mid+1,high);
			return;
		}
	else
		{
			binary_search(nums,key,low,mid-1);
		}
}

int main()
{
	ll n,q,p,s=0,i;
	cin>>n;
	vector<int>nums(n);
	vector<int>sum(n);
	for(i=0;i<n;i++)
		{
			cin>>nums[i];
		}
	sort(nums.begin(),nums.end());
	for(i=0;i<n;i++)
		{
			s = s+nums[i];
			sum[i] = s;	
		}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>p;
		last_min = -1;
		binary_search(nums,p,0,n-1);
		if(last_min!=-1)
			cout<<last_min+1<<" "<<sum[last_min]<<endl;
		else
			cout<<"0 0"<<endl;
	}
	return 0;
}
