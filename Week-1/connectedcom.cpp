#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

void explore(int a,unordered_map<int,int> &m,unordered_map<int,vector<int>> adj){
	m[a]=1;
	for(auto x:adj[a])
		if(m[x]==0)
			explore(x,m,adj);
	return;

}


int dfs(unordered_map<int,int> &m,unordered_map<int,vector<int>> adj){
	int c=0;
	for(auto x:m)
		if(x.second==0){
			explore(x.first,m,adj);
			c++;
		}

	return c;
}


int32_t main(){
	int v,e;cin>>v>>e;
	unordered_map<int,vector<int>> adlist;
	unordered_map<int,int> vis;

	for(int i=0;i<v;i++)
		vis[i+1]=0;

	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		adlist[a].push_back(b);adlist[b].push_back(a);
	}
	cout<<dfs(vis,adlist)<<endl;
	
	return 0;


}