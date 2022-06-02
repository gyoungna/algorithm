#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;
int l, c;
vector<char> alpha;
void dfs(int len, int c_cnt, int v_cnt, string& ans, int idx);
int main() {

	cin >> l >> c;

	char temp;
	for (int i = 0; i < c; i++)
	{
		cin >> temp;
		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());
	string ans;
	dfs(0, 0, 0, ans, 0);

	
}
void dfs(int len, int c_cnt, int v_cnt, string &ans, int idx) {

	if (len == l)
	{
		if (c_cnt >= 1 && v_cnt >= 2)
			cout << ans << "\n";
		return;
	}
	for (int i = idx; i < alpha.size(); i++)
	{
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			c_cnt++;
		else
			v_cnt++;

		ans += alpha[i];
		len++;
		dfs(len, c_cnt, v_cnt, ans, i + 1);
		len--;
		ans = ans.substr(0, len);
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			c_cnt--;
		else
			v_cnt--;


	}
}



