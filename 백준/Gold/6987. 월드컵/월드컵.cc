// 풀이 보고 해결함
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int b[4][6][3];
int res[4][6][3];
int isvalid[4];
bool ans[4];
bool isFind = false;

void func(int ix, int i, int j) // 2중 for문처럼 백트래킹 돌리기
{

	if (i == 6)
	{
		ans[ix] = true;// 여기 도달했으면 찾은거
		return;
	}

	if (j == 6)
	{
		func(ix, i + 1, i + 2);
		return;
	}

	res[ix][i][0]++;
	res[ix][j][2]++;
	// 만약 i가 j를 이겼다는 결과를 기록했을 때 i팀이나 j팀이 주어진 값을 초과해버리는 경우는 쳐낸다
	if (res[ix][i][0] <= b[ix][i][0] && res[ix][j][2] <= b[ix][j][2]) 
		func(ix, i, j + 1);
	res[ix][i][0]--;
	res[ix][j][2]--;

	
	res[ix][i][2]++;
	res[ix][j][0]++;
	if (res[ix][i][2] <= b[ix][i][2] && res[ix][j][0] <= b[ix][j][0])
		func(ix, i, j + 1);
	res[ix][i][2]--;
	res[ix][j][0]--;

	res[ix][i][1]++;
	res[ix][j][1]++;
	if (res[ix][i][1] <= b[ix][i][1] && res[ix][j][1] <= b[ix][j][1])
		func(ix, i, j + 1);
	res[ix][i][1]--;
	res[ix][j][1]--;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> b[i][j][k];
				isvalid[i] += b[i][j][k];
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (isvalid[i] == 30)
		{
			func(i, 0, 1);
		}
		if (ans[i])
			cout << 1;
		else
			cout << 0;
		cout << ' ';
	}


	return 0;
}