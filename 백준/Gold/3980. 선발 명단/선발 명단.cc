#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool isUsed[11];

void func(vector<vector<int>>& b, int k, int res, int& ans) // k번째 슨슈
{
	if (k == 11)
	{
		ans = max(ans, res);
		return;
	}
	for (int i = 0; i < 11; i++)
	{
		if (isUsed[i] || b[k][i] == 0) continue; // i번 포지션을 이미 뽑았으면
		isUsed[i] = true;
		res += b[k][i];
		func(b, k + 1, res, ans);
		res -= b[k][i];
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<vector<int>> b(11, vector<int>(11, 0));
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cin >> b[i][j];
			}
		}

		int ans = 0;
		func(b, 0, 0, ans);
		cout << ans << '\n';
	}


	return 0;
}

