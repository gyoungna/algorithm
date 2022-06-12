#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>


using namespace std;



int main() {
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> rb;
	int i = 0;
	char tmp = s[i];
	i++;
	while (i != s.length())
	{
		if (s[i] != tmp)
		{
			int num = tmp== 'R' ? 0 : 1;
			rb.push_back(num);
			tmp = s[i];
		}
		i++;

	}
	int num = s[s.length()-1] == 'R' ? 0 : 1;
	rb.push_back(num);
	cout << rb.size() / 2 + 1 << "\n";
}

