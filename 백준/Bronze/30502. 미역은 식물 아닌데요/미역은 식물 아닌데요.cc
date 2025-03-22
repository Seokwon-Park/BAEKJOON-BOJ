#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int P[1005];
int M[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int is = 0;
	int isNot = 0;

	fill(P, P + 1005, -1);
	fill(M, M + 1005, -1);

	for (int i = 0; i < m; i++)
	{
		int x;
		char y;
		bool z;
		cin >> x >> y >> z;
		if (y == 'P')
		{
			P[x] = z;
		}
		else if (y == 'M')
		{
			M[x] = z;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (P[i] == 1 && M[i] == 0)
		{
			is++;
		}
		if (P[i] == 0 || M[i] == 1)
		{
			isNot++;
		}
	}

	cout << is << ' ' << n - isNot;


	return 0;
}