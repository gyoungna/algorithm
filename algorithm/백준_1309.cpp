#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int num[100000]={0, };
int main() {


	int n;
	cin >> n;
	num[n - 1] = 1;
	int sum = 0;
	for (int i = n - 2; i >= 0; i--)
	{
			num[i] = 1+num[i+1]+sum*2;
			sum += num[i + 1];
			num[i] = num[i] % 9901;
		
	}
	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		cnt += num[i] * 2;
		cnt = cnt % 9901;
	}


	cout << cnt << "\n";
}


/*다른 답안
각 행의 경우의 수는 ox, xo, xx.  각각을 0,1,2방법으로 구분
n번째 행의 i번째 방법 dp[n][i]

dp[n][0]=dp[n-1][1]+dp[n-1][2];
dp[n][1]=dp[n-1][0]+dp[n-1][2];
dp[n][2]=dp[n-1][0]+dp[n-1][1]+dp[n-1][2];

int main(){
int n;
cin>>n;
dp[1][0]=1;
dp[1][1]=1;
dp[1][2]=1;

for(int i=2;i<=n;i++)
{
 dp[i][0]=dp[i-1][1]+dp[i-1][2];
 dp[i][1]=dp[i-1][0]+dp[i-1][2];
 dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
}

cout<<dp[n][[0]+dp[n][1]+dp[n][2]<<"\n";

*/
