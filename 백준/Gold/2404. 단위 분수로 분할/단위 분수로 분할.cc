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

int p, q, n, a;
int ans;
vector<pii> his;

void func(ll curp, ll curq, ll curn, ll mul, ll deno)
{
	if (curn > n) return;
	if (curp == 0)
	{
		//for (auto [nume, deno] : his)
		//{
		//	cout << nume << ' ' << deno << '\n';
		//}
		ans++;
		return;
	}

	for (ll i = deno; i * mul <= a; i++)
	{
		ll pp = curp * i - curq;
		ll qq = curq * i;
		if (pp < 0) continue;
		ll g = gcd(pp, qq);
		pp /= g;
		qq /= g;
		//his.push_back({ 1,i });
		func(pp, qq, curn + 1, mul * i, i);
		//his.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> p >> q >> a >> n;

	ll g = gcd(p, q);
	p /= g;
	q /= g;

	func(p, q, 0, 1, 1);
	cout << ans;

	return 0;
}