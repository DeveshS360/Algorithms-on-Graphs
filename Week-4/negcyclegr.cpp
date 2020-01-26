#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


int32_t main(){
	int mindis=0;
	int v,e;cin>>v>>e;
	vector<int> dis(v,INT_MAX);

	map<pair<int,int>,int> w;
	int f=0;
	
	unordered_map<int,vector<int>> adj;
	for(int i=0;i<e;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		adj[a].push_back(b);
		w[make_pair(a,b)]=c;
	}

	for(int i=0;i<v;i++)
		dis[i]=INT_MAX;
	for(int i=0;i<v-1;i++)
		for(auto x:adj)
			for(auto a:x.second)
				if(dis[a]>dis[x.first]+w[make_pair(x.first,a)])
					dis[a]=dis[x.first]+w[make_pair(x.first,a)];

	
	
		for(auto x:adj)
			for(auto a:x.second)
				if(dis[a]>dis[x.first]+w[make_pair(x.first,a)])
					f=1;

	if(f)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}
				
