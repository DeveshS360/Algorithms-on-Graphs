#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

int bfs(unordered_map<int,int> &dis,unordered_map<int,vector<int>> &adjlist,int sou,int des){
	queue<int> q;
	q.push(sou);
	dis[sou]=0;
	while(!q.empty()){
		int a=q.front();q.pop();
		for(auto x:adjlist[a])
			if(dis[x]==INT_MAX)
			{
				q.push(x);
				dis[x]=dis[a]+1;
			}

	}
	return dis[des];
}

int32_t main(){
	int v,e;cin>>v>>e;
	unordered_map<int,vector<int>> adjlist;
	unordered_map<int,int> dis;

	for(int i=0;i<v;i++)
		dis[i+1]=INT_MAX;

	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int sou,des;cin>>sou>>des;
	if(bfs(dis,adjlist,sou,des)==INT_MAX)
		cout<<"-1"<<endl;
	else
		cout<<bfs(dis,adjlist,sou,des)<<endl;


}