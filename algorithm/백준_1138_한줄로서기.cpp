#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;


int line[10] = { 0 };
int main() {

	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		
		int cnt = 0;
		int idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (cnt == temp)
			{
				if (line[j] == 0)
				{
					idx = j;
					break;
				}
			}
			else {
				if (line[j] == 0)
					cnt++;
			}
		}
		line[idx] = i + 1;

		
	}
	for (int i = 0; i < n; i++)
		cout << line[i] << " ";

	cout << "\n";
	

}
