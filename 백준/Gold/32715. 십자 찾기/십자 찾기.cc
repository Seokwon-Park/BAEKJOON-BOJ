#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int b[2505][2505];
int pf[2505][2505];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
			pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + b[i][j];
		}
	}

	int ans = 0;
	for (int i = 1 + k; i <= n - k; i++)
	{
		for (int j = 1 + k; j <= m - k; j++)
		{
			//가로로 세로로 한번씩 체크하면 될듯?
			int w = pf[i][j+k] + pf[i - 1][j - k - 1] - pf[i - 1][j+k] - pf[i][j - k - 1];
			int h = pf[i+k][j] + pf[i - k - 1][j - 1] - pf[i+k][j-1] - pf[i - k - 1][j];
			if(w == k*2+1 && h == k*2+1) 
				ans++;
		}
	}
	cout << ans;

	return 0;
}
