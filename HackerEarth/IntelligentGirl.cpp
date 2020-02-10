#include<bits/stdc++.h>
using namespace std;

#define ll long long

stack<ll> ans;

ll process(string s, ll i)
{
	
	ll num = s[i]-'0';
	//cout<<"I: "<<i<<endl;
	if(i == s.length()-1)
	{
		if(num%2 == 1)
		{
			ans.push(0);
			return 0;
		}
		else
		{
			ans.push(1);
			return 1;
		}
	}
	else
	{
			//cout<<"CALLING"<<endl;		
			ll add = process(s,i+1);
			//cout<<"ADD : "<<add<<endl;
			ll cnt;
			if(num%2 == 0)
				cnt = 1+add;
			else
				cnt = add;
			//cout<<"COUNT : "<<cnt<<"I : "<<i<<endl;
			ans.push(cnt);
			return cnt;
	}
}
int main()
{
	string s;
	cin>>s;
	ll a = process(s,0);
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
	return 0;
}
