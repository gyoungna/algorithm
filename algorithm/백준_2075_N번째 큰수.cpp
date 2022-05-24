#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>


using namespace std;

int main() {

	int n;
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> temp;
			min_heap.push(temp);
			if (min_heap.size() > n)
				min_heap.pop();
		}
		


	}


	cout << min_heap.top() << "\n";


}
