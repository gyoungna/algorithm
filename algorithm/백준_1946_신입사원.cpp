#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main() {

	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<pair<int, int>> v;
		pair<int, int> temp;
		for (int j = 0; j < n; j ++ ) {
			cin >> temp.first >> temp.second;

			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		int min = v[0].second;
		int cnt = n;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second > min)
			{
				cnt--;
			}
			else {
				min = v[i].second;
			}
		}
		cout << cnt << "\n";
	}

	

}
