#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 500

//dijkstra
int dist[MAXN];
int adj[MAXN][MAXN];
int visit[MAXN];

int teams[MAXN];
int n, m, start, en;

int pathNum[MAXN], teamNum[MAXN];

void dijkstra( int start )
{
    pathNum[start] = 1;
    teamNum[start] = teams[start];
    for( int v=0;v<n;v++ )
    {

        int lMin=INF;
        int pos;
        for( int i=0;i<n;i++ )
        {
            if( !visit[i]&&dist[i]<lMin)
            {
                lMin = dist[i];
                pos = i;
            }
        }
        visit[pos] = 1;
        for( int i=0;i<n;i++ )
        {
            if( !visit[i]&&adj[pos][i]<INF)
            {
                if( dist[i]>dist[pos]+adj[pos][i] )
                {
                    dist[i] = dist[pos] + adj[pos][i];
                    teamNum[i] = teamNum[pos] + teams[i];
                    pathNum[i] = pathNum[pos];
                }else if( dist[i]==dist[pos]+adj[pos][i] ){
                    pathNum[i] += pathNum[pos];
                    if( teamNum[i] < teamNum[pos] + teams[i] )
                        teamNum[i] = teamNum[pos] + teams[i];
                }
            }
        }
    }
}

int main()
{
    int c1, c2, l;
    cin >> n >> m >> start >> en;
    for( int i=0;i<n;i++ )cin >> teams[i];
    for( int i=0;i<n;i++ )
    {
        dist[i] = INF;
        for( int j=0;j<n;j++ )
            adj[i][j] = INF;
    }
    for( int i=0;i<m;i++ )
    {
        cin >> c1 >> c2 >> l;
        adj[c1][c2] = adj[c2][c1] = l;
    }

    dist[start] = 0;

    dijkstra(start);

    cout << pathNum[en] << " " << teamNum[en];
    return 0;
}