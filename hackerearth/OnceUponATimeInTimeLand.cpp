#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll> dp;

ll findMaxSum(vector<ll> nums,ll index,ll k)
{
	//Base-case
	if(index>= nums.size())
		return 0;
	
	if(dp.find(index)!=dp.end())
		return dp.find(index)->second;
	
	//Check if it is a +ive number
	if(nums[index]>0)
	{
		//Either choose the number or dont
		ll ans = max(nums[index]+findMaxSum(nums,index+k+1,k),findMaxSum(nums,index+1,k));
		dp.insert(make_pair(index,ans));
		return ans;
	}
	else
	{
		//Skip the number
		ll ans = findMaxSum(nums,index+1,k);
		dp.insert(make_pair(index,ans));
		return ans;
	}
}
int main()
{
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<ll> nums(n,0);
		for(ll i=0;i<n;i++)
			cin>>nums[i];
			
		cout<<findMaxSum(nums,0,k)<<endl;
	}
	return 0;
}
