#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int dist[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter the edges: " << endl;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    bfs(0);

    cout << "Shortest distances from node 0: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

