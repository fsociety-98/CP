#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll findNextFreeRow(vector<ll>& dp,vector<ll> &start,ll pref,ll k)
{

	ll count=0,i=start[pref];

	while(true)
	{
		if(dp[i]<k)
			{
				start[pref]=i;
				return i;
			}

		i = (i+1 == dp.size())?0:i+1;
		count++;

		if(count>dp.size())
			break;
	}
	return -1;
}



ll countMisplaced(ll n,ll m,ll k,vector<ll>& pref)
{

	//DP to store number of seats occupied in each row
	vector<ll> dp(m,0);
	vector<ll> start(m,0);

	ll i,place;
	ll count = 0;

	//Initialize
	for(i=0;i<m;i++)
		start[i] = i;


	for(i=0;i<n;i++)
	{

		if(dp[pref[i]-1] < k)
		{
			dp[pref[i]-1] = dp[pref[i]-1] + 1;
		}
		else
		{
			count++;

			//Place the student
			place = findNextFreeRow(dp,start,pref[i]-1,k);


			if(place !=-1)
				dp[place] = dp[place]+1;
			else
			{
			    count = count + (n - i - 1);
			    break;
			}
		}

	}
	return count;
}
int main()
{
	ll n,m,k;

	cin>>n>>m>>k;

	vector<ll> pref(n);

	for(ll i=0;i<n;i++)
		cin>>pref[i];

	cout<<countMisplaced(n,m,k,pref)<<endl;

	return 0;
}