#include<bits/stdc++.h>
using namespace std;

int mark1[100],mark2[100],dis[100],t=0;
void dfs2(int ,vector<int> *);

int dfs1(int v,vector<int> g[])
{
	mark1[v]=1;
	int mn=dis[v]=++t;
	for(int i=0;i<g[v].size();i++)
	{
		if(mark1[g[v][i]]==0)
			mn=min(mn,dfs1(g[v][i],g));
		else if(mark1[g[v][i]]==1)
			mn=min(mn,dis[g[v][i]]);
	}
	if(mark2[v]==0&&mn==dis[v])
	{
		dfs2(v,g);
		cout<<endl;
	}
	mark1[v]=2;
	return mn;
}

void dfs2(int v,vector<int> g[])
{
	mark2[v]=1;
	for(int i=0;i<g[v].size();i++)
		if(mark2[g[v][i]]==0)
			dfs2(g[v][i],g);
	cout<<v<<" ";
}

int main()
{
	int n,m,a,b;
	cout<<endl<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>m;
	vector<int> g[n+1],gt[n+1];
	cout<<endl<<"ENTER THE EDGE DETAILS  :  \n";
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	stack<int> s;
	bool mark[n+1];
	memset(mark1,0,sizeof(mark1));
	memset(mark2,0,sizeof(mark2));
	cout<<endl<<"STRONGLY CONNECTED COMPONENTS ARE  :  "<<endl;
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs1(i,g);
}
