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

int ttoi(string s)
{
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	return h * 60 + m;
}

string week[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	int st1, x1, st2, x2;
	st1 = ttoi(a);
	st2 = ttoi(b);
	x1 = ttoi(c);
	x2 = ttoi(d);

	int x = st2 - st1;
	int g = gcd(x1, x2);
	if (x % g != 0)
	{
		cout << "Never";
	}
	else
	{
		while (st1 != st2)
		{
			if (st1 < st2)
			{
				st1 += x1;
			}
			else if (st1 > st2)
			{
				st2 += x2;
			}
		}
		int day = st1 / 1440;
		st1 %= 1440;
		int hour = st1 / 60;
		st1 %= 60;
		cout << week[day % 7] << '\n';
		cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << st1;
	}
	
	return 0;
}