#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;



int main() {

	int n, k;

	cin >> n >> k;

	vector<int> height;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		height.push_back(tmp);
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 1; i < n; i++)
	{
		heap.push(height[i] - height[i - 1]);
	}
	long long int ans = 0;
	for (int i = 0; i < n - k; i++)
	{
		ans += heap.top();
		heap.pop();
	}

	cout << ans << "\n";
	
}
