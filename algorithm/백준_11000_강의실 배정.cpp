/*
priority_queue
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
	
	int n;
	cin >> n;

	
	int s, t;
	vector<pair<int, int>> v;


	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;

		v.push_back(temp);

	}

	sort(v.begin(), v.end());

	priority_queue<int,vector<int>,greater<int>> q;

	q.push(v[0].second);
	for (int i = 1; i < n; i++)
	{
		if (q.top() <= v[i].first)
		{
			q.pop();
			q.push(v[i].second);
		}
		else {
			q.push(v[i].second);
		}
	}

	cout << q.size() << "\n";

}
