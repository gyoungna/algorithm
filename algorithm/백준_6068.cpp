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

	priority_queue<pair<int, int>> time;
	pair<int, int> tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.second >> tmp.first;
		time.push(tmp);
	}
	int ans = 1000000;
	while (!time.empty())
	{
		int finish = time.top().first;
		int do_time = time.top().second;
		time.pop();
		if (finish< ans)
		{
			ans = finish - do_time;
		}
		else {
			ans = ans - do_time;
		}

		
	}

	if (ans < 0)
		ans = -1;
	
	cout << ans << "\n";

}

