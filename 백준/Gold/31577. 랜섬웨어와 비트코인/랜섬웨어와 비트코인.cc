#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int pc[15][8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pc[i][j] = (i * 8 + j) % 20 + 1;
		}
		sort(pc[i], pc[i] + 8);
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << pc[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}