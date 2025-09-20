#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int s;
	double d, t;
	cin >> s >> d >> t;

	if (s * 5280 / 3600 * t >= d)
	{
		cout << "MADE IT";
	}
	else
	{
		cout << "FAILED TEST";
	}
	
	return 0;
}