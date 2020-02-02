#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define m 1000000007
map<ll, vector<ll> > dp;

vector<ll> matrix_mul(vector<ll> a,vector<ll> b)
{
	ll a00 = ((a[0]*b[0])%m +(a[1]*b[2])%m)%m;
	ll a01 = ((a[0]*b[1])%m +(a[1]*b[3])%m)%m;
	ll a10 = ((a[2]*b[0])%m +(a[3]*b[2])%m)%m;
	ll a11 = ((a[2]*b[1])%m +(a[3]*b[3])%m)%m;
	
	vector<ll> ans;
	ans.push_back(a00);
	ans.push_back(a01);
	ans.push_back(a10);
	ans.push_back(a11);
	
	return ans;
}
 
set<ll> powers(ll n)
{
	ll temp =n;
	ll pwr = 1;
	set<ll> ans;
	while(temp>0)
	{
		if(temp%2==1)
			ans.insert(pwr);
		
		temp = temp/2;
		pwr = pwr*2;
			
	}
	
	return ans;
}


ll findWays(ll n)
{
	if(n==1)
		return 2;
	if(n==2)
		return 3;
	vector<ll> ans;
	vector<ll> inter;
	
	inter.push_back(1);
	inter.push_back(1);
	inter.push_back(1);
	inter.push_back(0);
	
	ll pwr = 1;
	ll count = 0;
	set<ll> pwrs = powers(n-2);
	//cout<<"POWERS FOUND "<<endl;
/*	set<ll>::iterator itr = pwrs.begin();
	while(itr!=pwrs.end())
	{
		cout<<*itr<<endl;
		itr++;
	}
*/
	while(true)
	{
		/*
		if(dp.find(pwr)!=dp.end())
			inter = dp.find(pwr)->second;
		else
		{
			if(pwr!=1)
				{
					inter = matrix_mul(inter,inter);	
					dp.insert(make_pair(pwr,inter));
				}
		}	
		*/
		
		if(pwr!=1)
			{
				//cout<<"MUL"<<endl;
				inter = matrix_mul(inter,inter);
				//cout<<"res"<<endl;
			}
		
		//cout<<"PWR "<<pwr<<endl;
		if(pwrs.find(pwr)!=pwrs.end())
		{
			//cout<<"INSIDE"<<endl;
			count++;
			if(ans.empty())
				{
					//cout<<"INNER"<<endl;
					ans = inter;
					//cout<<"I@"<<endl;
				}
			else
				ans = matrix_mul(ans,inter);
		}
		
		pwr = pwr * 2;
		
		if(count >= pwrs.size())
			break;
	}
	return ((ans[0]*3)%m+(ans[1]*2)%m)%m;
}
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<findWays(n)<<endl;
	}
	return 0;
}
