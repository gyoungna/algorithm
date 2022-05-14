#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int main() {

	string s;
	cin >> s;
	string c;
	cin >> c;
	stack<char> stack_s;
	stack<int> stack_i;
	int idx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		stack_s.push(s[i]);
		if (s[i] == c[idx])
		{
			
			idx++;
			stack_i.push(idx);
			if (idx == c.length())
			{
				for (int j = 0; j < c.length(); j++) {
					stack_i.pop();
					stack_s.pop();
				}
				if (stack_i.empty())
					idx = 0;
				else
					idx = stack_i.top();
			}
		}
		else {
			idx = 0;
			if (s[i] == c[idx])
			{
				idx++;
				stack_i.push(idx);
				if (idx == c.length())
				{
					for (int j = 0; j < c.length(); j++) {
						stack_i.pop();
						stack_s.pop();
					}
					if (stack_i.empty())
						idx = 0;
					else
						idx = stack_i.top();
				}
			}
			else
				stack_i.push(idx);
		}

		
	}
	vector<char> ans;
	while (!stack_s.empty()) {
		ans.push_back(stack_s.top());
		stack_s.pop();
	}

	if (ans.empty())
		cout << "FRULA";
	else
	{
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i];
	}
	cout << "\n";
}
