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
		string s_num;
		vector<int> num;
		string z;

		cin >> s_num;
		for (int i = 0; i < s_num.length(); i++)
		{
			num.push_back(s_num[i] - '0');
		}
		cin >> z;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (z[i] == '*') {
				ans++;
				if (i - 1 >= 0)
					num[i - 1]--;
				num[i]--;
				if (i + 1 < n)
					num[i + 1]--;
			}
		}
		

		for (int i = 0; i < n; i++)
		{
			if (i % 3 == 2)
			{
				ans += num[i - 1];
			}
			if (i == n - 1 && i % 3 !=2)
			{
				ans += num[i];
			}
		}

		cout << ans << "\n";
		
	}

}
