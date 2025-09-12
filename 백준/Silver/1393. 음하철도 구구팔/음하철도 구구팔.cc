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

	int xs, ys, xe, ye, dx, dy;
	cin >> xs >> ys >> xe >> ye >> dx >> dy;

	if (dx == 0 && dy == 0)
	{
		cout << xe << ' ' << ye;
	}
	else if (dx == 0)
	{
		if ((dy ^ (ys - ye)) >= 0)
		{
			cout << xe << ' ' << ys;
		}
		else
		{
			cout << xe << ' ' << ye;
		}
	}
	else if (dy == 0)
	{
		if ((dx ^ (xs - xe)) >= 0)
		{
			cout << xs << ' ' << ye;
		}
		else
		{
			cout << xe << ' ' << ye;
		}
	}
	else
	{
		int ymul1 = dx;
		int a1 = dy;
		int b1 = -xe * a1 + ye * dx;

		int ymul2 = dy;
		int a2 = -dx;
		int b2 = -xs * a2 + ys * dy;

		int l = lcm(ymul1, ymul2);
		a1 *= (l / ymul1);
		b1 *= (l / ymul1);

		a2 *= (l / ymul2);
		b2 *= (l / ymul2);

		//a1 -= a2;
		//b2 -= b1;

		int x = (b2 - b1) / (a1 - a2);
		int y = (a1 * x + b1) / l;

		if ((dx ^ (x - xe)) >= 0 && (dy ^ (y - ye)) >= 0)
		{
			cout << x << ' ' << y;
		}
		else
		{
			cout << xe << ' ' << ye;
		}
	}



	return 0;
}