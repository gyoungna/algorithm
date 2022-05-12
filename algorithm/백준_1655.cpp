#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> max_heap;
	priority_queue<int> min_heap;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (max_heap.size() > min_heap.size()) min_heap.push(-temp);
		else max_heap.push(temp);

		if (!max_heap.empty() && !min_heap.empty()) {
			if (max_heap.top() > -min_heap.top()) {
				int min_top = -min_heap.top();
				int max_top = max_heap.top();

				min_heap.pop();
				max_heap.pop();
				min_heap.push(-max_top);
				max_heap.push(min_top);
			}

		}

		cout << max_heap.top() << "\n";


	}

}
