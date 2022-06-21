#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {

	int n, m;

	cin >> n >> m;

	priority_queue<int> plus;
	priority_queue<int> minus;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp > 0)
			plus.push(tmp);
		else if (tmp < 0)
			minus.push(abs(tmp));
	}
	int ans = 0;
	
	if (plus.empty()) {
		ans += minus.top();
		for (int i = 0; i < m && !minus.empty(); i++)
			minus.pop();
	}
	else if (minus.empty()) {
		ans += plus.top();
		for (int i = 0; i < m && !plus.empty(); i++)
			plus.pop();

	}
	else if (plus.top() < minus.top())
	{
		ans += minus.top();
		for(int i=0;i<m&&!minus.empty();i++)
		minus.pop();
	}
	else {
		ans += plus.top();
		for (int i = 0; i < m && !plus.empty(); i++)
			plus.pop();
	}

	while (!plus.empty())
	{
		ans +=( plus.top() * 2);
		for (int i = 0; i < m&&!plus.empty(); i++)
		{
			plus.pop();
		}
	}
	while (!minus.empty())
	{
		ans += (minus.top() * 2);
		for (int i = 0; i < m && !minus.empty(); i++)
		{
			minus.pop();
		}
	}

	cout << ans << "\n";
}
