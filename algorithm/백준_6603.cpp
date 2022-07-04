#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

void dfs(vector<int> s, int cnt, int k, vector<int> ans, int idx);
int main() {

	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
			return 0;

		vector<int> s;
		int tmp;
		for (int i = 0; i < k; i++)
		{
			cin >> tmp;
			s.push_back(tmp);
		}

		for (int i = 0; i < k - 5; i++)
		{
			vector<int> ans;
			dfs(s, 0, k, ans, i);
		}
		cout << "\n";
	}
	
}
void dfs(vector<int> s, int cnt,int k,vector<int> ans,int idx)
{
	ans.push_back(s[idx]);
	cnt++;
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx + 1; i < k; i++)
	{
		dfs(s, cnt, k, ans, i);
	}
}

