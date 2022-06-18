#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {

	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		priority_queue<int> q;
		int tmp;
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			q.push(tmp);
		}
		
		int min_level = 0;
		
		bool r = true;
		int first = q.top();
		q.pop();
		int right= q.top();
		q.pop();
		if (abs(first - right) > min_level)
			min_level = abs(first - right);
		int left = q.top();
		q.pop();
		if (abs(first - left) > min_level)
			min_level = abs(first - left);

		while (!q.empty())
		{
			int num = q.top();
			q.pop();
			if (r) {
				if (abs(right - num) > min_level)
					min_level = abs(right - num);
				right = num;
				r = false;
			}
			else {
				if (abs(left - num) > min_level)
					min_level = abs(left - num);
				left = num;
				r = true;
			}
		}

		cout << min_level << "\n";
	}
	
}
