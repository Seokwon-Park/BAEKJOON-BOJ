#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	int d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int days = (d * 360 + e * 30 + f) - (a * 360 + b * 30 + c);
	int month = min(days / 30, 36);
	int year = days/360 * 15;
	int y = days / 360;

	for (int i = 0; i < y; i++)
	{
		year += i / 2;
	}


	
	cout << year << ' ' << month << '\n';
	cout << days << "days";


	return 0;
}