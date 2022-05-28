#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> ans;
vector<vector<int>> tmp;
void square(int n,long long int b);

int main() {
	
	int n;
	long long int b;


	cin >> n >> b;
	int temp;
	for (int i = 0; i < n; i++)
	{
		vector<int> row;

		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}
	ans = matrix;
	square( n,b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j]%1000 << " ";
		}
		cout << "\n";
	}
}
void square(int n, long long int b)
{
	if (b == 1)
		return;

	if (b % 2 == 1)
	{
		square(n, b / 2);
		tmp = ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = 0;
				for (int k = 0; k < n; k++)
				{
					sum += ((tmp[i][k] * tmp[k][j]) % 1000);
					sum = sum % 1000;
					//cout << i<<j<<sum << "**";
				}
				ans[i][j] = sum;
			}
		}
		tmp = ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = 0;
				for (int k = 0; k < n; k++)
				{
					sum += ((tmp[i][k] * matrix[k][j]) % 1000);
					sum = sum % 1000;
					//cout << i<<j<<sum << "**";
				}
				ans[i][j] = sum;
			}
		}

	}
	else {
		square(n, b / 2);
		tmp = ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = 0;
				for (int k = 0; k < n; k++)
				{
					sum += ((tmp[i][k] * tmp[k][j]) % 1000);
					sum = sum % 1000;
					//cout << i<<j<<sum << "**";
				}
				ans[i][j] = sum;
			}
		}
	}
	


}
