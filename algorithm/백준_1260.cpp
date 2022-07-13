#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;


bool visit[1001] = { false, };
vector<int> dfs_ans;
map<int, vector<int>> graph;
vector<int> bfs_ans;
void dfs(int root);
void bfs(vector<int> same_depth);
int main() {

	int n, m, start;
	cin >> n >> m>>start;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}
	for (int i = 1; i <= n; i++)
	{
		if(!graph[i].empty())
			sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(start);
	for (int i = 1; i <= n; i++)
		visit[i] = false;
	vector<int> depth;
	depth.push_back(start);
	visit[start] = true;
	bfs(depth);
	for (int i = 0; i < dfs_ans.size(); i++)
	{
		cout << dfs_ans[i] << " ";
	}
	cout << "\n";
	
	
	
	for (int i = 0; i < bfs_ans.size(); i++)
	{
		cout << bfs_ans[i] << " ";
	}
	cout << "\n";
}
void dfs(int root)
{
	visit[root] = true;
	dfs_ans.push_back(root);

	for (int i = 0; i < graph[root].size(); i++)
	{
		if (!visit[graph[root][i]])
		{
			dfs(graph[root][i]);
		}
	}
}
void bfs(vector<int> same_depth)
{
	vector<int> new_depth;
	if (same_depth.empty())
		return;

	for (int i = 0; i < same_depth.size(); i++)
	{
		bfs_ans.push_back(same_depth[i]);
	}
	for (int i = 0; i < same_depth.size(); i++)
	{
		for (int j = 0; j < graph[same_depth[i]].size(); j++) {
			if (!visit[graph[same_depth[i]][j]]) {
				visit[graph[same_depth[i]][j]] = true;
				new_depth.push_back(graph[same_depth[i]][j]);
			}
		}
	}
	bfs(new_depth);
	
}
/*
* void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}
*/
