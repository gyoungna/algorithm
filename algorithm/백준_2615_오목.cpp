#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int game[19][19] = { 0, };
int left_i = -1;
int left_j = -1;
bool win = false;
int winner = 0;
void dfs(int i, int j, int& cnt, int bw,int l, int r);
int main() {

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> game[i][j];
		}
	}



	for (int j = 0; j < 19; j++)
	{
		for (int i = 0; i < 19; i++) {

			if (game[i][j] != 0)
			{
				int cnt = 1;

				if (j + 1 < 19) {
					dfs(i, j, cnt, game[i][j],0,1);
					if (win)
					{
						if (j - 1 >= 0 && game[i][j] == game[i][j - 1])
						{
							win = false;
						}
						else {
							left_i = i;
							left_j = j;
							winner = game[i][j];
							break;
						}
					}
				}
				cnt = 1;
				if (i - 1 >= 0 && j + 1 < 19) {
					dfs(i ,j , cnt, game[i][j],-1,1);
					if (win) {
						if (j - 1 >= 0 && i + 1 < 19&& game[i][j] == game[i + 1][j - 1])
							win = false;
						else {
							left_i = i;
							left_j = j;
							winner = game[i][j];
							break;
						}
					}
				}
				cnt = 1;
				if (i + 1 < 19) {
					dfs(i, j, cnt, game[i][j], 1, 0);
					if (win)
					{
						if (i - 1 >= 0 && game[i][j] == game[i -1][j])
							win = false;
						else {
							left_i = i;
							left_j = j;
							winner = game[i][j];
							break;
						}
					}
				}
				cnt = 1;
				if (i + 1 < 19 && j + 1 < 19) {
					dfs(i, j , cnt, game[i][j],1,1);
					if (win)
					{
						if (i - 1 >= 0 && j -1>=0 && game[i][j] == game[i - 1][j - 1])
							win = false;
						else {
							left_i = i;
							left_j = j;
							winner = game[i][j];
							break;
						}
					}

				}
			}
			

		}

		if (win)
			break;
	}


	cout << winner << "\n";
	if (winner != 0)
		cout << left_i + 1 << " " << left_j + 1 << "\n";


}
void dfs(int i, int j, int& cnt, int bw,int l, int r)
{


	if (game[i+l][j+r] == bw)
	{
		cnt++;
		if (cnt == 5)
		{
			win = true;

		}
		if (cnt == 6) {
			win = false;
			return;
		}
		dfs(i + l, j + r, cnt, bw, l, r);
	}

	   
}
