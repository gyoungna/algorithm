#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int rest_water(int n);
int main() {
	

	int n, k;
	cin >> n >> k;
	int ans = 0;
	if (n <= k)
		cout << 0 << "\n";
	else {

		while (true)
		{
			int rest = rest_water(n);
			if (rest <= k) break;

			n++;
			ans++;

		}
		cout << ans << "\n";
	}
	



}
int rest_water(int n) {

	int ans = 0;

	while (n != 0)
	{
		if (n % 2 == 1)
			ans++;
		n = n / 2;
	}

	return ans;
}
