#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char v[1005][5];
int zero[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == '0')
			{
				zero[i] = j;
			}
		}
	}

	// i번으로 길을 맞추는 경우를 구한다.
	int ans = INF;
	for (int i = 0; i < 4; i++)
	{
		int res = 0;
		for (int j = 0; j < n-2; j++)
		{
			// i번 열과 j번 행의 0이있는 열의 좌표 차이
			int mov = abs(zero[j] - i);
			if (mov == 3)
			{
				mov = 1;
			}
			res += mov;
		}
		ans = min(ans, res);
	}
	//--->
	ans += 3;
	// |
	// |
	// V
	ans += n - 1;

	cout << ans;

	return 0;
}
