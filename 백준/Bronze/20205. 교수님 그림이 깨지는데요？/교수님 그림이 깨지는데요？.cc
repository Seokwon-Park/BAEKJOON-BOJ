#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int nn[10][10];
int nk[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nn[i][j];
		}
	}

	for (int i = 0; i < n * k; i++)
	{
		for (int j = 0; j < n *k; j++)
		{
			cout << (nk[i][j] = nn[i/k][j/k]) << ' ';
		}
		cout << '\n';
	}


	return 0;
}

