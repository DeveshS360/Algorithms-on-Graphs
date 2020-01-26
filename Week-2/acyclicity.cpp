#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

void explore(int a,unordered_map<int,vector<int>> adj,int &flag,unordered_map<int,char> &color){
	color[a]='g';
	for(auto x:adj[a]){
		if(color[x]=='g')
			flag=1;
		else if(color[x]=='w')
			explore(x,adj,flag,color);
	}
	color[a]='b';
	return;

}


int dfs(unordered_map<int,vector<int>> adj,unordered_map<int,char> &color){
	int flag=0;
	for(auto x:color)	
		if(x.second=='w')
			explore(x.first,adj,flag,color);



	return flag;
}


int32_t main(){
	int v,e;cin>>v>>e;
	unordered_map<int,vector<int>> adlist;
	unordered_map<int,int> vis;
	unordered_map<int,char> color;

	for(int i=0;i<v;i++){
		vis[i+1]=0;
		color[i+1]='w';
	}

	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		adlist[a].push_back(b);
	}
	if(dfs(adlist,color))
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	
	return 0;


}