#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>


using namespace std;



int main() {
	
	int k;

	cin >> k;

	int a = 1;
	int b = 2;

	int min_size;

	if (k == 1)
		min_size = 1;
	else {
		while (true)
		{
			if (a < k && k <= b)
			{
				min_size = b;
				break;
			}
			a = a * 2;
			b = b * 2;
		}
	}

	int temp_k= k;
	int temp_s = min_size;
	int cnt = 0;

	while (true)
	{
		if (temp_k>=temp_s)
		{
			temp_k = temp_k - temp_s;
			
		}
		if (temp_k == 0)
			break;
		else
		{
			temp_s = temp_s / 2;
			cnt++;
		}

	}

	cout << min_size << " " << cnt << "\n";
}

