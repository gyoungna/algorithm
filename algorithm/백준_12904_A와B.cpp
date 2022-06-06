#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>


using namespace std;


int main() {

	string s, t;

	cin >> s >> t;
	int ans = 0;
	for (int i = t.length() - 1; i >= 0; i--)
	{
		if (t == s)
		{
			ans = 1;
			break;
		}
		if (t[i] == 'A')
		{
			t=t.substr(0, t.length() - 1);
		}
		else if (t[i] == 'B')
		{
			t=t.substr(0, t.length() - 1);
			reverse(t.begin(), t.end());
		}
	}
	cout << ans << "\n";

}

