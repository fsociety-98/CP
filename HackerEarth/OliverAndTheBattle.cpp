#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll search(ll row,ll col,bool ** visited,int** troops,ll n,ll m)
{
	int count = 0;
	queue< pair<int,int> > bfs_queue;
	int r[] = {0,0,1,1,1,-1,-1,-1};
	int c[] = {1,-1,0,1,-1,0,1,-1};
	bfs_queue.push(make_pair(row,col));
	visited[row][col]=true;
	while(!bfs_queue.empty())
	{
		//Pop the first  element
		pair<int,int> ele = bfs_queue.front();
		
		//Explore this ele
		for(ll i=0;i<8;i++)
		{
			ll rr = ele.first+r[i];
			ll cc = ele.second+c[i];
			
			if(rr<0 || cc<0 || rr>=n||cc>=m||visited[rr][cc]||troops[rr][cc]!=1)
				continue;
			
			count++;
			bfs_queue.push(make_pair(rr,cc));
			visited[rr][cc]=true;
		}
		bfs_queue.pop();
	}
	return count;
}
int main()
{
	ll t,n,m;
	ll i,j;
	
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		
		//Stores the input matrix
		int** troops = new int*[n];
		bool** visited = new bool*[n];
		
		for(i=0;i<n;i++)
		{
			troops[i] =new int[m];
			visited[i] = new bool[m];
			
			for(j=0;j<m;j++)
				{
					cin>>troops[i][j];
					visited[i][j]=false;
				}
		}
		
		//Stores number of troops
		ll no_of_troops = 0;
		//Stores maximum troop size
		ll max_troop_size= -1;
		
		//Find the first member of non visited troop
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				//If not a visited troop member
				if(troops[i][j]==1 && !visited[i][j])
				{
					//Newly found troop, so inc. no_of_troops
					no_of_troops++;
					
					//BFS the troop and return the size
					ll troop_size = search(i,j,visited,troops,n,m);
					
					//Compare
					if(troop_size>max_troop_size)
					{
						max_troop_size=troop_size;
					}
				}
			}
		}
		cout<<no_of_troops<<" "<<max_troop_size+1<<endl;
		delete visited;
		delete troops;
	}
	return 0;
}
