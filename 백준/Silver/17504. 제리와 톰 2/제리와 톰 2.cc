#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[16];
int n;

pair<ll,ll> func(int k)
{
	if (k == n - 1)
	{
		return { v[k], 1 };
	}
	auto [nume, deno] = func(k + 1);
	swap(nume, deno);
	ll add = v[k];
	nume = deno * add + nume;
	return { nume,deno };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	auto [nume, deno] = func(0);

	swap(nume, deno);

	ll g = gcd(nume, deno);
	nume /= g;
	deno /= g;

	cout << deno - nume << ' ' << deno;

	return 0;
}