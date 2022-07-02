#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;


int main() {

	int n;
	cin >> n;
	vector<pair<int, int>> crain;
	int tmp;
	pair<int, int> t;
	for (int i = 0; i < n; i++) {
		cin >> t.first;
		t.second = 0;
		crain.push_back(t);
	}

	sort(crain.begin(), crain.end());
	int m;
	cin >> m;
	priority_queue<int> box;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		box.push(tmp);
	}
	int idx = n-1;
	if (crain[n - 1].first < box.top())
	{
		cout << -1 << "\n";
		return 0;
	}
	int ans = 0;
	while (!box.empty()) {

		if (crain[idx].first >= box.top())
		{
			box.pop();
			crain[idx].second++;
			if (ans < crain[idx].second)
			{
				ans = crain[idx].second;
				for (int i = n - 1; i >= idx + 1; i--)
				{
					if (box.empty())
						break;
					box.pop();
					crain[i].second++;
				}
			}
			else if (ans > crain[idx].second)
			{
				while (crain[idx].second < ans && !box.empty())
				{
					box.pop();
					crain[idx].second++;
				}
			}
			idx--;
			if (idx == -1)
				idx = n - 1;

		}
		else {
			idx++;

		}



	}
	cout << ans << "\n";
}
