#include <iostream>
#include <cstring>
using namespace std;

#define INF 0x7FFFFF
#define MAXN 500

int n, m, start, en;
int visit[MAXN];
int adj[MAXN][MAXN];
int teams[MAXN];
int pathNum = 0, teamNum = 0, MinDist = INF;

void dfs( int start, int dist, int teamValue)
{
	if( start==en )
	{
		if( dist<MinDist )
		{
			MinDist = dist;
			pathNum = 1;
			teamNum = teamValue;
		}else if( dist==MinDist ){
			pathNum++;
			if( teamValue>teamNum )teamNum = teamValue;
		}
		return;
	}
	visit[start] = 1;
	for( int i=0;i<n;i++ )
	{
		if( !visit[i]&&adj[start][i]>0 )
			dfs(i, dist+adj[start][i],teamValue+teams[i]);
	}
	visit[start] = 0;
}

int main()
{
	int c1, c2 , l;
	cin >> n >> m >> start >> en;
	memset(adj, -1, sizeof(adj));
	for( int i=0;i<n;i++ )cin >> teams[i];
	for( int j=0;j<m;j++ )
	{
		cin >> c1 >> c2 >> l;
		adj[c1][c2] = adj[c2][c1] = l;
	}

	dfs(start, 0, teams[start]);
	cout << pathNum << " " << teamNum;
	return 0;
}