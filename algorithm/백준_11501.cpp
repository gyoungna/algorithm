#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {

	
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int tmp;
		vector<long long int> num;
		priority_queue<pair<int, int>> heap;
		int max_num = -10001;
		//int min_idx = 0;
		int max_idx = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			num.push_back(tmp);
			pair<int, int> p;
			p.first = tmp;
			p.second = i;
			heap.push(p);
		}
		long long int ans = 0;
		int min_idx= 0;
		while (!heap.empty()) {
			max_num = heap.top().first;
			max_idx = heap.top().second;
			if (min_idx <= max_idx)
			{
				for (; min_idx <= max_idx; min_idx++)
				{
					ans += (max_num - num[min_idx]);
				}
			}
			heap.pop();

		}
		cout << ans << "\n";
	}
}
