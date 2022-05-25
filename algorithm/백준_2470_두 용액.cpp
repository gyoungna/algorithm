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
	long long int temp;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		min_heap.push(temp);
		max_heap.push(temp);

	}

	int min_first = 0;
	int min_second = 0;
	int min = 2000000000;
	while (!max_heap.empty() && !min_heap.empty()) {

		int a = min_heap.top();
		int b = max_heap.top();
		if(a==b)
			break;

		if (abs(a + b) < min)
		{
			min = abs(a + b);
			min_first = a;
			min_second = b;
		}

		if (abs(a) > abs(b))
		{
			min_heap.pop();
		}
		else
			max_heap.pop();

	}

	int t;
	if (min_first > min_second)
	{
		t = min_first;
		min_first = min_second;
		min_second = t;

	}

	cout << min_first << " " << min_second << "\n";

}
