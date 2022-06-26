#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;



int main() {

	int n;
	cin >> n;

	vector<int> b;
	int cnt = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp % 2 == 1)
		{
			tmp--;
			cnt++;
		}
		b.push_back(tmp);
	}
	int zero = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (b[i] == 0)
			zero++;

	}if (zero == n)
	{
		cout << cnt << "\n";
		return 0;
	}
	else
		zero = 0;
	while (true)
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			b[i] = b[i] / 2;
			if (b[i] % 2 == 1)
			{
				b[i]--;
				cnt++;
			}
			if (b[i] == 0)
				zero++;
			
		}
		if (zero == n)
			break;
		else
			zero = 0;
	}

	cout << cnt << "\n";

}

