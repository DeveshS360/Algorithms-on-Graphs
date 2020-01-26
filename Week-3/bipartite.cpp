#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

void bfs(unordered_map<int,int> &dis,unordered_map<int,vector<int>> &adjlist,int sou,unordered_map<int,char> &color){
	queue<int> q;
	q.push(sou);
	dis[sou]=0;
	while(!q.empty()){
		int a=q.front();q.pop();
		if(dis[a]%2==0)
			color[a]='r';
		else
			color[a]='g';
		for(auto x:adjlist[a])
			if(dis[x]==INT_MAX)
			{
				q.push(x);
				dis[x]=dis[a]+1;
			}

	}
	return;
}

int32_t main(){
	int v,e;cin>>v>>e;
	unordered_map<int,vector<int>> adjlist;
	unordered_map<int,int> dis;
	unordered_map<int,char> color;

	for(int i=0;i<v;i++)
		dis[i+1]=INT_MAX;

	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for(int i=0;i<v;i++)
		if(dis[i+1]==INT_MAX)
			bfs(dis,adjlist,i+1,color);

	
	int flag=0;
	for(auto x:adjlist){
		for(auto a:x.second)
			if(color[x.first]==color[a])
				{
					flag=1;
					break;
				}
		if(flag)
			break;
	}

	if(flag)
		cout<<"0"<<endl;
	else
		cout<<"1"<<endl;	
	return 0;

}