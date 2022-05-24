#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> v;
	map<int, int> f;
	int temp;
	double average = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		average += temp;
		f[temp]++;
	}
	sort(v.begin(), v.end());
	average = round(average / n);
	int center = v[n / 2 ];

	int max_f = 0;
	bool second = false;
	int min_val = 0;
	int second_val = 0;
	for (auto iter = f.begin(); iter != f.end(); iter++)
	{
		if (iter->second > max_f) {
			max_f = iter->second;
			second_val= iter->first;
			second = false;
		}
		else if (iter->second == max_f)
		{
			if (!second)
			{
				
					second_val = iter->first;
					second = true;
				
			}
		}
		
	}
	
	
	cout << (int)average << "\n";
	cout << v[n / 2] << "\n";
	cout <<second_val << "\n";
	cout << v[n - 1] - v[0] << "\n";
	
  /*
  int max_f = 0;
	for (auto iter = f.begin(); iter != f.end(); iter++)
	{
		if (iter->second > max_f)
			max_f = iter->second;
		
	}
	set<int> f_s;
	for (auto iter = f.begin(); iter != f.end(); iter++)
	{
		if (iter->second == max_f)
			f_s.insert(iter->first);
	}
	auto iter = f_s.begin();
	if(f_s.size()>1)
		iter++;
	
	cout << (int)average << "\n";
	cout << v[n / 2] << "\n";
	cout << *(iter) << "\n";
	cout << v[n - 1] - v[0] << "\n";
	*/

}
