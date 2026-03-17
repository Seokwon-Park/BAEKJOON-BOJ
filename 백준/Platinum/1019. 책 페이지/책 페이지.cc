// 솔루션 참고함
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

ll v[10];

void func(int x, int d)
{
	while (x > 0)
	{
		v[x % 10] += d;
		x /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll st = 1;
	ll en = n;

	ll d = 1;
	while (1)
	{
		while (st % 10 != 0 && st <= en)
		{
			func(st, d);
			st++;
		}

		while (en % 10 != 9 && st <= en)
		{
			func(en, d);
			en--;
		}

		if (st > en)
		{
			break;
		}

		st /= 10;
		en /= 10;

		ll cnt = en - st + 1;
		cnt *= d;
		for (int i = 0; i < 10; i++)
		{
			v[i] += cnt;
		}

		d *= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}