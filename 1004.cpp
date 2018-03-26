//counting leaves
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAXN 100

map< int, vector<int> > ch;
int levelLeaf[MAXN] = {0}, level[MAXN] = {0};
int n, m;

void level_dfs(int root)
{
	vector<int>::iterator iter = ch[root].begin();
	for( ;iter!=ch[root].end();++iter )
	{
		level[*iter] = level[root] + 1;
		if( *iter>=n )return;
		level_dfs(*iter);
	}
}

void judge(int node)
{
	if( ch[node].empty() )levelLeaf[level[node]]++;
}

int main()
{
	int ID, k, ele;
	cin >> n >> m;
	for( int i=0;i<m;i++ )
	{
		cin >> ID >> k;
		for( int j=0;j<k;j++ )
		{
			cin >> ele;
			ch[ID].push_back(ele);
		}
	}
	level[1] = 1;
	level_dfs(1);
	for( int s=1;s<=n;s++ )
	{
		judge(s);
	}
	for( int i=level[1];i<=level[n];i++ )
	{
		cout << levelLeaf[i];
		if( i!=level[n] )cout << " ";
	}
	return 0;
}
