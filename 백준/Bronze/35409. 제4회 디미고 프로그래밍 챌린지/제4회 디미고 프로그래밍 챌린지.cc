#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int t[8][2] = {
	{390, 540},
	{590, 600},
	{650, 660},
	{710, 720},
	{770, 830},
	{880, 890},
	{940, 950},
	{1000, 1370}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, m;
	cin >> h >> m;
	for (int i = 0; i < 8; i++)
	{
		int x = h * 60 + m;
		if (x >= t[i][0] && x <= t[i][1])
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}