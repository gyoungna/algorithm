#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>


using namespace std;



int main() {
	
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);
	}

	int ans = 0;

	while (q.size() != 1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		ans += a + b;
		q.push(a + b);
	}
	cout << ans<<"\n";

}

