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

	int d;
	cin >> d;
	vector<int> v(d + 1, 1);
	for (int i = 1; i <= d; i++)
	{
		cin >> v[i];
	}

	ll cur = 0;
	ll child = 1;
	ll left = 1;
	for (int gen = 1; gen <= d; gen++)
	{
		left = gen * (left - 1) + v[gen];
		left %= MOD;
		cout << (cur + left) % MOD << '\n';
		child = child * gen;
		child %= MOD;
		cur += child;
		cur %= MOD;
	}

	return 0;
}