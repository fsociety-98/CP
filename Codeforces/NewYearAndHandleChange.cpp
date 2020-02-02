#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> count_lower_upper(string s,ll index)
{
	ll lwr = 0;
	ll upr = 0;
	
	for(ll i=index;i<s.length();i++)
	{
		if(islower(s[i]))
			lwr++;
		else
			upr++;
	}
	
	vector<ll> ans;
	ans.push_back(lwr);
	ans.push_back(upr);
	return ans;
}

//map< pair<ll,ll>, pair<ll,ll> > dp;

vector<ll> MinLowerUpper(string s,ll k,ll l,ll index)
{
	if(k==0)
		return count_lower_upper(s,index);
		
	if(index+l-1 >= s.length())
		return count_lower_upper(s,index);
	
	vector<ll> ans;
	
	// 3 cases
	// First case : Skip the current char
	ll skip_lwr,skip_upr,skip_ans;	
	ans = MinLowerUpper(s,k,l,index+1);
	skip_lwr = ans[0];
	skip_upr = ans[1];
	skip_ans = min(skip_upr,skip_lwr);
	
	//Second case : Take to_upper of next l charecters
	ll tu_lwr,tu_upr,tu_ans;
	ans = MinLowerUpper(s,k-1,l,index+l);
	tu_lwr = ans[0];
	tu_upr = l+ans[1];
	tu_ans = min(tu_upr,tu_lwr);
	
	
	//Third case : Take to_lower of next l charecters
	ll tl_lwr,tl_upr,tl_ans;
	ans = MinLowerUpper(s,k-1,l,index+l);
	tl_lwr = l+ans[0];
	tl_upr = ans[1];
	tl_ans = min(tl_lwr,tl_upr);
	
	ans.clear();
	if(tl_ans<tu_ans && tl_ans<skip_ans)
	{
		ans.push_back(tl_lwr);
		ans.push_back(tl_upr);
		return ans;
	}
	else if(tu_ans<tl_ans && tu_ans<skip_ans)
	{
		ans.push_back(tu_lwr);
		ans.push_back(tu_upr);
		return ans;
	}
	else
	{
		ans.push_back(skip_lwr);
		ans.push_back(skip_upr);
		return ans;
	}
	
}
int main()
{
	ll n,k,l;
	string s;
	
	cin>>n>>k>>l;
	cin>>s;
	vector<ll> ans = MinLowerUpper(s,n,k,l);
	cout<<min(ans[0],ans[1])<<endl;
	return 0;
}
