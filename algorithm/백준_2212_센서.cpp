#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector<int> x;
vector<int> dist;
int main() {
	int n, k;
	
	cin >> n >> k;
	int temp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		x.push_back(temp);
	}
	sort(x.begin(), x.end());

	for (int i = 1; i < n; i++)
	{
		dist.push_back(x[i] - x[i - 1]);
	}

	sort(dist.begin(), dist.end());
	int len = 0;
	for (int i = 0; i < n - k; i++)
		len += dist[i];

	cout << len << "\n";


	

}
