#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool b[10][13] =
{
	{1,1,1,1,1,1,1,1,0,1,0,1,1},
	{1,0,1,0,1,1,1,1,1,0,0,1,1},
	{1,0,1,0,1,1,1,1,1,0,0,1,1},
	{1,1,1,0,1,1,1,1,0,0,0,1,1},
	{1,0,1,0,1,1,1,1,0,0,0,1,1},
	{1,0,1,0,1,1,1,1,0,0,0,1,1},
	{1,0,1,0,1,1,1,1,0,0,0,1,1},
	{1,0,1,0,1,1,1,1,0,0,0,1,1},
	{1,0,1,0,1,1,1,1,0,0,0,1,1},
	{1,1,1,0,0,1,1,1,0,0,0,1,1}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << count(b[n - 1], b[n - 1] + 13, 1) << '\n';
	for (int i = 0; i < 13; i++)
	{
		if (b[n - 1][i] == true)
		{
			cout << (char)('A' + i) << ' ';
		}
	}

	return 0;
}
