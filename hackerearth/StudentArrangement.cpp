
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ll n,m,k,ch,count=0;
	
	cin>>n>>m>>k;
	
	unordered_map<ll,ll> dp;
	unordered_map<ll,ll>::iterator itr,itr2;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		itr = dp.find(ch);
		if(itr == dp.end())
			dp.insert(make_pair(ch,1));
		else
			{
				if(itr->second == k)
				{
					count++;
					
					ll cur_ch = (ch==n)?1:ch+1;
					itr2 = dp.find(cur_ch);
					
					if(itr2 == dp.end())
						{
							dp.insert(make_pair(cur_ch,1));
							continue;
						}
					ll inner_count=0;
					while(inner_count<n)
					{
						inner_count++;
						if(itr2->second <k)
							{
								itr2->second = itr2->second+1;
								break;
							}
						else
							{
								cur_ch = (cur_ch==n)?1:cur_ch+1;
								itr2 = dp.find(cur_ch);
								continue;
							}
					}
				}
				else
					itr->second = itr->second+1;
			}
	}
	cout<<count<<endl;
	return 0;
}
