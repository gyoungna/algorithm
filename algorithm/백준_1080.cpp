#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int main() {


	int row, col;
	cin >> row >> col;

	vector<string> a;
	vector<string> b;

	string tmp;
	int cnt = 0;

	for (int i = 0; i < row; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < row; i++)
	{
		cin >> tmp;
		b.push_back(tmp);
	}


		for (int i = 0; i < row - 2; i++)
		{
			for (int j = 0; j < col - 2; j++)
			{
				if (a[i][j] != b[i][j])
				{
					cnt++;
					for (int k = 0; k < 3; k++)
					{
						for (int l = 0; l < 3; l++)
						{
							a[i + k][j + l] = a[i + k][j + l] == '1' ? '0' : '1';

						}
					}
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (a[i][j] != b[i][j]) {
					cnt = -1;
					break;

				}
			}
		}

	cout << cnt << "\n";

}
