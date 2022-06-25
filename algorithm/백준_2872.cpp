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
	map<int, int> books;
	priority_queue<int> max_heap;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		books[tmp] = i;
		max_heap.push(tmp);

	}
	int top = max_heap.top();
	max_heap.pop();
	int cnt = 0;
	while (!max_heap.empty())
	{
		if (books[top] < books[max_heap.top()])
		{
			cout << max_heap.size()<<"\n";
			return 0;
		}
		else {
			top = max_heap.top();
			max_heap.pop();
		}
	}

	cout << max_heap.size() << "\n";

	
}

