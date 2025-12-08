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

	int n, p;
	cin >> n >> p;
	vector<ll> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	bool init = b[0] == 1;
	bool last = b[n - 1] == n / p + (n % p != 0);
	bool inc = true;
	bool ball = true;

	for (int i = 1; i < n; i++)
	{
		if (b[i] > b[i - 1] + 1 || b[i] < b[i - 1]) inc = false;
		if (b[i] * p < (i + 1)) ball = false;
	}

	if (init && last && inc && ball) cout << "YES";
	else cout << "NO";

	return 0;
}