#include<bits/stdc++.h>
using namespace std;
#define ll long long

//win[0] -> sathyam
//win[1] -> kunal
ll win[2];

// turn ->0 for sathyam
// turn->1 for kunal
void func(int turn,int red,int green)
{
	int other = (turn==0)?1:0;
	if(green==0 && red==0)
		{
			win[0]+=1;
			return;
		}
	if(green==0)
		{
			win[turn]+=1;
			return;
		}
	if(red == 0)
		{
			win[other]+=1;
			return;
		}
		
	//Do both cases
	//Pick red
	win[turn]+=red;
	//Pick Green
	for(ll i=0;i<green;i++)
		func(other,red,green-1);
}

int main()
{
	win[0] = 0;
	win[1] = 0;
	
	func(0,2,1);
	cout<<(1.0*win[0])/(win[1]+win[0])<<endl;
	return 0;
}
