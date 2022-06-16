#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {
	
	int n, m;
	vector<long long int> num;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		long long int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		sort(num.begin(), num.end());
		long long int a = num[0];
		long long int b = num[1];

		num[0] = a + b;
		num[1] = a + b;
	}

	long long int sum = 0;
	for (int i = 0; i < num.size(); i++)
	{
		sum += num[i];
	}

	cout << sum << "\n";
}
