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

	priority_queue<pair<int, int>> assignment;
	pair<int, int> tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.second >> tmp.first;
		assignment.push(tmp);
	}
	
	int ans = 10000000000;
	while(!assignment.empty())
	{
		int time = assignment.top().second;
		int hour = assignment.top().first;
		assignment.pop();
		if (hour < ans)
		{
			ans = hour;
		}
		ans = ans - time;
		
	}

	
	cout << ans << "\n";

}

