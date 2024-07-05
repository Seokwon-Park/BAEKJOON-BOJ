#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[105][105];
int used[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	bool chk = false;
	int sum = n * (n * n + 1) / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (used[b[i][j]])
			{
				chk = true;
			}
			used[b[i][j]]++;
		}
	}
	if (chk)
	{
		cout << "FALSE";
		return 0;
	}

	int diag1 = 0;
	int diag2 = 0;
	for (int i = 0; i < n; i++)
	{
		int hsum = 0;
		int wsum = 0;
		diag1 += b[i][i];
		diag2 += b[i][n - i - 1];
		for (int j = 0; j < n; j++)
		{
			hsum += b[j][i];
			wsum += b[j][i];
		}
		if (hsum != sum || wsum != sum)
		{
			cout << "FALSE";
			return 0;
		}
	}

	if (diag1 != sum || diag2 != sum)
	{
		cout << "FALSE";
		return 0;
	}

	cout << "TRUE";

	return 0;
}