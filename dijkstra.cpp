/*
 *find the shortest path from v0 to every other node
 *using dijkstra
 * Input: 
 *       n : number of nodes, arcs[v][w] : adjacency matrics
 * Output;
 *       all the distance(dist[i]) from v0 to the rest nodes 
 */
#include <iostream>
#include <cstdio>
using namespace std;

#define INF 0x3f3f3f3f
int adj[10][10];//邻接矩阵
int dist[10];//保存最短路径
int visit[10];//若visit[i]=1,则vi has been traversaled
int v0=0;
int v, w, n, m;
int c1, c2, l;
int lMin;
int pos;//the nearest node

int main()
{
    cin >> n >> m;
    for( int i=0;i<n;i++ )
    {
        dist[i] = INF;
        for( int j=0;j<n;j++ )
            adj[i][j]=INF;
    }
    for( int i=0;i<m;i++ )
    {
        cin >> c1 >> c2 >> l;
        adj[c1][c2] = adj[c2][c1] = l;
    }
    visit[v0] = 1;
    dist[v0] = 0;
    for( v=0;v<n;v++ )
    {
        lMin = INF;
        for( w=0;w<n;w++ )//find the nearest node of v
        {
            if( !visit[w]&&dist[w]<lMin )
            {
                lMin = dist[w];
                pos = w;
            }
        }
        visit[pos] = 1;
        for( w=0;w<n;w++ )//update distance of node around the pos
        {
            if( !visit[w]&&adj[pos][w]<INF )
            {
                if( dist[w]>dist[pos]+adj[pos][w] )
                    dist[w] = dist[pos] + adj[w][pos];
            }
        }
    }
    for( int i=0;i<n;i++ )
        cout << dist[i] << " ";
    return 0;
}
