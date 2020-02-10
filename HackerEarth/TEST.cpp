#include<bits/stdc++.h>
using namespace std;

void change(string s)
{
	 s.append("---");
	 cout<<"Changed s: "<<s<<endl;
}
int main()
{
	string s;
	cin>>s;
	change(s);
	cout<<s<<endl;
	return 0;
}
