#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


int32_t main(){
	int v,e;cin>>v>>e;
	vector<int> dis(v,INT_MAX);
	set<pair<int,int>> ms;
	map<pair<int,int>,int> w;
	
		

	unordered_map<int,vector<int>> adj;
	for(int i=0;i<e;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		adj[a].push_back(b);
		w[make_pair(a,b)]=c;
	}

	
	int src,des;cin>>src>>des;
	src--,des--;
	dis[src]=0;
	ms.insert(make_pair(0,src));
	while(!ms.empty())
	{	
		pair<int,int> b=*ms.begin();
		int a=b.second;
		ms.erase(ms.begin());
	
		 for(auto x:adj[a])
			if(dis[x]> dis[a]+w[pair<int,int>(a,x)]){
				if(dis[x]!=INT_MAX)
					ms.erase(ms.find(make_pair(dis[x],x)));
				dis[x]=dis[a]+w[make_pair(a,x)];
				
				ms.insert(make_pair(dis[x],x));
			}
	}
	if(dis[des]==INT_MAX)
		cout<<"-1"<<endl;
	else
	cout<<dis[des]<<endl;
	return 0;

}