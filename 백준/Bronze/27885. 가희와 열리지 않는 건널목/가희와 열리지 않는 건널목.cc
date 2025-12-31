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

int toSec(string hms)
{
	int h = stoi(hms.substr(0, 2));
	int m = stoi(hms.substr(3, 2));
	int s = stoi(hms.substr(6, 2));

	return h * 3600 + m * 60 + s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<bool> v(86400, 1);
	int c, h;
	cin >> c >> h;
	for (int i = 0; i < c; i++)
	{
		string hms;
		cin >> hms;
		int res = toSec(hms);
		fill(v.begin() + res, v.begin() + res + 40, 0);
	}
	for (int i = 0; i < h; i++)
	{
		string hms;
		cin >> hms;
		int res = toSec(hms);
		fill(v.begin() + res, v.begin() + res + 40, 0);
	}

	cout << count(v.begin(), v.end(), 1);

	return 0;
}
