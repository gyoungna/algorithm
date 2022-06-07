#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {
	
	int a, b;

	cin >> a >> b;

	int ans = 0;
	bool no = false;
	while (a < b)
	{
		int last = b % 10;

		if (last%2==0)
		{
			b = b / 2;
			ans++;
		}
		else if (last == 1)
		{
			b = (b - 1) / 10;
			ans++;
		}
		else {
			no = true;
			ans = -1;
			break;
		}
	}
	if (ans > 0)
		ans++;
	if (a > b)
		ans = -1;

	cout << ans << "\n";


}
