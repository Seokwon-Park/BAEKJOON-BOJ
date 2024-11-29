#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll hp, atk, ehp, eatk;
	cin >> hp >> atk >> ehp >> eatk;
	ll p, s;
	cin >> p >> s;
	
	ll limit = hp / eatk;
	if (hp % eatk != 0)
	{
		limit++;
	}

	ll tmp = ehp / atk * atk;
	if (atk <= p || ehp - tmp > 0 && ehp - tmp <= p)
	{
		ehp += s;
	}

	ll damage = atk * limit;
	if (damage < ehp)
	{
		cout << "gg";
		return 0;
	}
	else
	{
		cout << "Victory!";
	}
	

	return 0;
}