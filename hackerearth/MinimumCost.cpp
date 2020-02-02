#include<bits/stdc++.h>
using namespace std;

#define ll long long



struct qnode
{
	ll index;
	ll cost;	
};

ll findMinCost(vector<ll>& permutation, ll target)
{
	
	// 3 cases
	// Add the 0 cost node if not already added
	// Add the 2 other neighbouring nodes
	
	queue<qnode> min_q;
	ll cost = 0;
	qnode* q = new qnode();
	qnode temp;
	q->cost = 0;
	q->index = 1;
	min_q.push(*q);
	
	while(!min_q.empty())
	{
		temp = min_q.front();
		
		if(temp.index == target)
			return temp.cost;
		
		qnode* s = new qnode();
		s->index = permutation[temp.index-1];
		s->cost = temp.cost;
		min_q.push(*s);
		
		qnode* t = new qnode();
		t->cost = temp.cost+1;
		t->index = temp.index+1;
		min_q.push(*t);
		
		if(temp.index-1>=1)
		{
			qnode* x = new qnode();
			x->cost = temp.cost+1;
			x->index = temp.index - 1;
			min_q.push(*x);
		}
		
		min_q.pop();
	}
	
	return -1;
}
int main()
{
	ll t,n,i;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		vector<ll> p(n);
		
		for(i=0;i<n;i++)
			cin>>p[i];
		
		queue<ll> min;
		
		cout<<findMinCost(p,n)<<endl;
	}
	return 0;
}
