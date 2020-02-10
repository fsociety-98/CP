#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct str
{
	ll strength;
	ll count;
	ll index;
};

bool myComparer(struct str& a, struct str & b)
{
	return a.strength < b.strength;
}

ll search_lower(vector<str>& s,ll max_index)
{
	ll low = 0,ans = 0,mid;
	ll max = s[max_index].strength;
	ll high = max_index-1;

	while(low<=high)
	{
		mid = (low+high)/2;
		if(s[mid].strength>=max)
		{
			// Search left
			high = mid -1;
		}
		else
		{
			ans = mid+1;
			low = mid+1;
		}
	}

	return ans;
}
void print_wins(vector<str>& s)
{

	ll low,high,i,ans;
	vector<ll>a(s.size());
	for(i=0;i<s.size();i++)
	{
		ans = search_lower(s,i);

		ans = (ans - s[i].count <0)?0:ans -s[i].count;

		a[s[i].index] = ans;

		cout<<" Index : "<<s[i].index<<endl;
		cout<<"Strength : "<<s[i].strength<<endl;
		cout<<"COUNT : "<<s[i].count<<endl;
		cout<<"ANS : "<<ans<<endl<<endl<<endl;
	}
	
	for(i=0;i<a.size();i++)
	    cout<<a[i]<<" ";
}
int main()
{
	ll n,k,i;

	cin>>n>>k;

	vector<str> s(n);
	

	for(i=0;i<n;i++)
		{
		    cin>>s[i].strength;
		    s[i].index = i;
		    s[i].count = 0;
		}

	ll a,b;
	for(i=0;i<k;i++)
	{
		cin>>a>>b;
		s[a-1].count = s[a-1].count + (s[a-1].strength>s[b-1].strength)?1:0;
		s[b-1].count = s[b-1].count + (s[b-1].strength>s[a-1].strength)?1:0;				
	}

	sort(s.begin(),s.end(),myComparer);

	print_wins(s);
	return 0;
}