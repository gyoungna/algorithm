//union-find

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;
int parent[5001] = { 0, };
int find(int x);
void merge(int x, int y);
int main() {

	int n = 1;
	int m = 1;

	int cnt = 1;
	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		else {
			string answer;


			for (int i = 1; i <= n; i++)
				parent[i] = i;

			int p1, p2;
			for (int i = 0; i < m; i++)
			{
				cin >> p1 >> p2;

				int px = find(p1);
				int py = find(p2);

				if (px == py) {
					parent[px] = -1;
				}
				else if (py == -1)
				{
					parent[px] = py;
				}
				else {
					merge(p1, p2);
				}

			}
				set<int> num;
				map<int, int> m;
				int ans = 0;
				for (int i = 1; i <= n; i++)
				{

					int root = find(i);
					if (root != -1) {
						num.insert(root);
					}
						
				}

				if (num.size()== 1)
				{
					cout << "Case " << cnt << ": There is one tree." << "\n";
				}
				else if (num.size() == 0)
					cout << "Case " << cnt << ": No trees." << "\n";
				else {
					cout << "Case " << cnt << ": A forest of " << num.size() << " trees." << "\n";
				}
			cnt++;


		}
	}
}
int find(int x) {

	if (parent[x] == x || parent[x] == -1)
		return parent[x];
	else {
		return find(parent[x]);
	}

}
void merge(int x, int y) {

	int px = find(x);
	int py = find(y);

	parent[py] = px;
}
