#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

typedef pair<double,pair<int,int>> iPair;

double dist(pair<int,int> a,pair<int,int> b){
	return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));

}

int32_t main(){
	double distance=0;
	int n;cin>>n;
	map<pair<int,int>,double> dis;
	map<pair<pair<int,int>,pair<int,int>>,double> wgt;
	map<pair<int,int>,bool> added;
	//map<pair<int,int>,bool> vis;
	vector<pair<int,int>> pts(n);
	for(int i=0;i<n;i++)
	{
		int a,b;cin>>a>>b;
		pts[i]=(make_pair(a,b));
		dis[pts[i]]=INT_MAX;
		added[pts[i]]=0;
	}

	map<pair<int,int>,vector<pair<int,int>>> adj;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				adj[pts[i]].push_back(pts[j]);
			}
	for(auto x:adj)
		for(auto a:x.second)
			wgt[make_pair(x.first,a)]=dist(x.first,a);

	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
	for(int i=1;i<n;i++)
		pq.push(make_pair(INT_MAX,pts[i]));
	set<pair<int,int>> ms;

	pq.push(make_pair(0,pts[0]));
	while(ms.size()!=n)
	{

		iPair a=pq.top();pq.pop();
		if(added[a.second]==0)
			distance+=a.first;
		//cout<<a.second.first<<" "<<a.second.second<<" "<<a.first<<endl;
		ms.insert(a.second);
		added[a.second]=1;
		pair<int,int> b=a.second;
		for(auto x:adj[b])
			if(dis[x]>wgt[make_pair(x,b)] && added[x]==0){
				dis[x]=wgt[make_pair(x,b)];
				pq.push(make_pair(wgt[make_pair(x,b)],x));
			}
	}

	cout<<fixed<<setprecision(8)<<distance<<endl;
	return 0;
}