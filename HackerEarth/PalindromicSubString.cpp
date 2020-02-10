#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll global_max;
ll max_len(string s,int low,int high)
{
	cout<<"low "<<low<<" high "<<high<<endl;
	if(low>high)
		return 0;
	if(low==high)
		return 1;
	
	ll ans=0;
	for(ll i=low+1;i<=high;i++)
	{
			ll add = (s.at(low)==s.at(i))?2:0;
			ans = max(ans,max_len(s,low+1,i-1)+add);
			
				
			add = (s.at(low+1) == s.at(i))?1:0;
			ans = max(ans,max_len(s,low+1,i)+add);
			
				
			add = (s.at(low) == s.at(i-1))?1:0;
			ans = max(ans,max_len(s,low+1,i)+add);
			
		
	}
	if(ans == 0)
		return -1;
	
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	string str;
	while(t--)
	{
		cin>>str;
		global_max = 0;
		ll a = max_len(str,0,str.length()-1);
		cout<<a<<endl;
	}
	return 0;
}
