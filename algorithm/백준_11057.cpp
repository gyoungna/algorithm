#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int dp[1001][10] = { 0, };

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] = dp[i][j] % 10007;

		}
	}

	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		result += dp[n][i];
		result = result % 10007;
	}

	cout << result << "\n";
}


