#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {

	int n;

	cin >> n;

	string s1, s2;

	cin >> s1 >> s2;

	string tmp1, tmp2;
	tmp1 = s1;
	tmp2 = s1;
	tmp1[0] = tmp1[0] == '1' ? '0' : '1';
	tmp1[1] = tmp1[1] == '1' ? '0' : '1';
	int num1 = 1;//index 0 changed
	int num2 = 0;

	for (int i = 1; i < n-1; i++)
	{
		if (tmp1[i - 1] != s2[i - 1])
		{
			for(int j=0;j<3;j++)
				tmp1[i-1+j] = tmp1[i-1 + j] == '1' ? '0' : '1';
			num1++;
			//cout << tmp1 << "\n";
		}
		
		if (tmp2[i - 1] != s2[i - 1])
		{
			for(int j=0;j<3;j++)
				tmp2[i - 1 + j] = tmp2[i - 1 + j] == '1' ? '0' : '1';
			num2++;
			
		}

	}
	if (tmp1[n-2] != s2[n - 2])
	{
		tmp1[n - 2] = tmp1[n - 2] == '1' ? '0' : '1';
		tmp1[n - 1] = tmp1[n - 1] == '1' ? '0' : '1';
		num1++;
	}
	if (tmp2[n - 2] != s2[n - 2])
	{
		tmp2[n-2] = tmp2[n - 2] == '1' ? '0' : '1';
		tmp2[n - 1] = tmp2[n - 1] == '1' ? '0' : '1';
		num2++;
	}

	if (tmp1[n - 1] != s2[n - 1])
		num1 = -1;
	if (tmp2[n - 1] != s2[n - 1])
		num2 = -1;

	if (num1 == -1 && num2 == -1)
		cout << -1 << "\n";
	else if (num1 == -1)
		cout << num2 << "\n";
	else if (num2 == -1)
		cout << num1 << "\n";
	else
		cout << (num1 > num2 ? num2 : num1) << "\n";

	
}
