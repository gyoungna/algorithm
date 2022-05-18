#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

int main() {

	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		map<int, int> exist;

		string s;
		int num;
		for (int j = 0; j < n; j++)
		{
			cin >> s >> num;

			if (s == "I")
			{
				max_heap.push(num);
				min_heap.push(num);
				exist[num]++;
			}
			else {
				if (num == 1)
				{
					while (!max_heap.empty()&&!exist[max_heap.top()]) {
						max_heap.pop();
					}
					if (!max_heap.empty()) {
						exist[max_heap.top()]--;
						max_heap.pop();
						
					}

				}
				else {
					while (!min_heap.empty() && !exist[min_heap.top()]) {
						min_heap.pop();
					}
					if (!min_heap.empty()) {
						exist[min_heap.top()]--;
						min_heap.pop();
						
					}
				}
			}
		}

		while (!max_heap.empty() &&!exist[max_heap.top()]) {
			max_heap.pop();
		}
		while (!min_heap.empty() &&!exist[min_heap.top()]) {
			min_heap.pop();
		}

		if (!max_heap.empty()) {
			cout << max_heap.top() << " " << min_heap.top() << "\n";

		}
		else
			cout << "EMPTY" << "\n";
		

	}

}
/* multiset으로 푸는 방법
* #include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;
        char order;
        int num;
        multiset<int> ms;
        while (n--)
        {
            cin >> order >> num;
            if (order == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}
*/
