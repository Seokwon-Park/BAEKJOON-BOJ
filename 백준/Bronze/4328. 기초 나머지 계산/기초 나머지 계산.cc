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

string trans(ll x, int b)
{
	if (x == 0)
	{
		return "0";
	}
	
	string ret = "";
	while (x)
	{
		ret.push_back((x % b) + '0');
		x /= b;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll b;
	while (cin >> b)
	{
		if (b == 0) break;
		string numestr, denostr;
		cin >> numestr >> denostr;

		ll deno = 0;
		for (char i : denostr)
		{
			deno = deno * b + i - '0';
		}

		ll nume = 0;
		for (char i : numestr)
		{
			nume = (nume * b + i - '0') % deno;
		}

		cout << trans(nume, b) << '\n';
	}

	return 0;
}