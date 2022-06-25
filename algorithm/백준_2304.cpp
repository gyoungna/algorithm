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

	priority_queue<pair<int, int>> stock;

	pair<int, int> tmp;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp.second >> tmp.first;

		stock.push(tmp);
	}

	int front = stock.top().second;
	int back = stock.top().second + 1;
	int w = stock.top().first;
	stock.pop();
	while (!stock.empty())
	{
		pair<int, int> block = stock.top();
		stock.pop();

		if (block.second+1 > back)
		{
			w += (block.second+1 - back) * block.first;
			back = block.second+1;
		}
		else if (block.second < front)
		{
			w += (front - block.second) * block.first;
			front = block.second;
		}
	}
	cout << w << "\n";
}

