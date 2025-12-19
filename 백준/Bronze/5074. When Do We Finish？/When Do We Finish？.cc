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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	while (cin >> a >> b)
	{
		if (a == "00:00" && b == "00:00") break;
		int h = stoi(a.substr(0, 2)) + stoi(b.substr(0, 2));
		int m = stoi(a.substr(3)) + stoi(b.substr(3));
		h += m / 60;
		m %= 60;
		int d = h / 24;
		h %= 24;

		cout << setw(2) << setfill('0') << h << ':'
			<< setw(2) << setfill('0') << m;
		if (d > 0)
		{
			cout << " +" << d << '\n';
		}
		else
		{
			cout << '\n';
		}
	}

	return 0;
}
