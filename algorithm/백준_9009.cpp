#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector<int> fib;
int main() {

	int t;
	cin >> t;

	fib.push_back(0);
	fib.push_back(1);

	int idx = 2;
	while (fib[idx - 1] + fib[idx - 2] <= 1000000000)
	{
		fib.push_back(fib[idx - 1] + fib[idx - 2]);
		idx++;
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		vector<int> ans;
		for (int j = fib.size() - 1; j >= 0; j--)
		{
			if (n >= fib[j])
			{
				ans.push_back(fib[j]);
				n = n - fib[j];
			}
			if (n == 0)
				break;
		}

		for (int j = ans.size()-1;j>=0;j--)
		{
			cout << ans[j] << " ";
		}
		cout << "\n";
	}

}

