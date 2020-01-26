#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
}

void explore(int a,unordered_map<int,int> &m,unordered_map<int,vector<int>> &adj,vector<pair<int,int>> &postorder,int &post){
	m[a]=1;
	for(auto x:adj[a])
		if(m[x]==0)
			explore(x,m,adj,postorder,post);
	postorder.push_back(pair<int,int>(a,post));
	post++;

	return;

}
void dfs(unordered_map<int,int> &m,unordered_map<int,vector<int>> &adj,vector<pair<int,int>> &postorder,int &post){
	for(auto x:m)
		if(x.second==0)
			explore(x.first,m,adj,postorder,post);
	return;
}


int32_t main(){
	int v,e;cin>>v>>e;
	unordered_map<int,vector<int>> adlist,adlist2;
	unordered_map<int,int> vis;
	vector<pair<int,int>> postorder;
	int post=0;
	for(int i=0;i<v;i++)
		vis[i+1]=0;

	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		adlist[b].push_back(a);
		adlist2[a].push_back(b);
	}
	dfs(vis,adlist,postorder,post);
	int count=0;
	vector<pair<int,int>> po;
	po=postorder;
	sort(po.begin(),po.end(),compare);
	for(auto &x:vis)
		x.second=0;
	

	for(auto v:po)
		if(vis[v.first]==0)
		{
			explore(v.first,vis,adlist2,postorder,post);
			count++;
		}
	
	cout<<count<<endl;
	return 0;

}
