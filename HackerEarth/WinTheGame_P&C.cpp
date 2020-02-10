#include<bits/stdc++.h>
using namespace std;
#define ll long long

void print_ans(double a)
{
	cout<< fixed << setprecision(6) <<a<<endl;
}
int main()
{
	ll t,r,g,rtemp,gtemp;
	cin>>t;
	double ans,temp,total;
	while(t--)
	{
		cin>>r>>g;
		if(r==0 || g==0)
		{
			ans=1;
			print_ans(ans);
			continue;
		}
		
		ans = (r/(r+g*1.0));
		rtemp = r;
		gtemp = g;
		temp = 1;
		for(int i=0;i<g/2;i++)
		{
			total = gtemp+rtemp;
			temp = (gtemp/total)*((gtemp-1)/(total-1))*(rtemp/(total-2))*temp;
			gtemp = gtemp-2;
			ans = ans + temp;
		}
		print_ans(ans);
	}
	return 0;
}
