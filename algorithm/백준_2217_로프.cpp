#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> weight;
	int max_w =-1;

	int w;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		weight.push_back(w);

	}
	sort(weight.begin(), weight.end());
	int idx = n - 1;

	while (idx >= 0)
	{
		if (max_w < weight[idx] * (n - idx))
		{
			max_w = weight[idx] * (n - idx);
		}
		idx--;
	}

	cout << max_w << "\n";

}
