#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector<int> arr;
int cnt = 0;
int n, s;
void dfs(int idx, int& sum);
int main() {


    cin >> n >> s;
    int tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    int sum = 0;
    dfs(0, sum);

    cout << cnt << "\n";
}
void dfs(int idx, int& sum) {

    for (int i = idx; i < n; i++)
    {

        sum += arr[i];
        if (sum == s)
        {
            cnt++;
        }
        dfs(i + 1, sum);

        sum -= arr[i];

    }

}
