#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int f2, f1, f;
	int g1, g;
	cin >> f2 >> f1 >> f >> g1 >> g;

	int p2, p1, p, q2, q1, q;
	p2 = g1 * g1 * f2;
	p1 = g1 * g * 2 * f2 + f1 * g1;
	p = g * g * f2 + f1 * g + f;

	q2 = f2 * g1;
	q1 = f1 * g1;
	q = f * g1 + g;

	int r2, r1, r;
	r2 = p2 - q2;
	r1 = p1 - q1;
	r = p - q;

	if (r2 != 0)
	{
		int res = r1 * r1 - 4 * r2 * r;
		if (res > 0)
		{
			cout << "Go ahead";
		}
		else if (res == 0)
		{
			cout << "Remember my character";
		}
		else
		{
			cout << "Head on";
		}
	}
	else if (r1 != 0)
	{
		cout << "Remember my character";
	}
	else if (r == 0)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Head on";
	}

	return 0;
}