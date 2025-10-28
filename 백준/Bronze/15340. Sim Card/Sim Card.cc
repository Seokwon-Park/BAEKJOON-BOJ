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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, d;
	while (cin >> c >> d)
	{
		if (c == 0 && d == 0) break;
		cout << min({ 30 * c + 40 * d, 35 * c + 30 * d , 40 * c + 20 * d }) << '\n';
	}


	return 0;
}