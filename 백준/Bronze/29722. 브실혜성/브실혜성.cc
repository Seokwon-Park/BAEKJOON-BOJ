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

	string s;
	cin >> s;
	int y = stoi(s.substr(0, 4));
	int m = stoi(s.substr(5, 2));
	int d = stoi(s.substr(8));

	int n;
	cin >> n;
	d += n;
	if (d > 30)
	{
		m += (d - 1) / 30;
		d = (d - 1) % 30 + 1;
	}
	if (m > 12)
	{
		y += (m - 1) / 12;
		m = (m - 1) % 12 + 1;
	}
	cout << y << '-' << setw(2) << setfill('0') << m << '-' <<setw(2) << setfill('0') << d;



	return 0;
}