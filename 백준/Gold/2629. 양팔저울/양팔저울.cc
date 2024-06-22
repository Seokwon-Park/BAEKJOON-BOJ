#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int v[30];
int n;

bool dp[35][40005];

void func(int k, int w)
{
	if (dp[k][w]) return;
	dp[k][w] = true;
	if (k == n) return;
	func(k + 1, w + v[k]);
	func(k + 1, w);
	func(k + 1, abs(w - v[k]));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int m;
	cin >> m;

	func(0, 0);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (dp[n][k])
			cout << 'Y';
		else
			cout << 'N';
		cout << ' ';
	}



	return 0;
}
