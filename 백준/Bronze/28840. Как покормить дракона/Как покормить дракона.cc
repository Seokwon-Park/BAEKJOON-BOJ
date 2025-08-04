#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	
	int atime = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3));
	int btime = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3));
	int day = 24 * 60;
	int res = 0;
	if (atime < btime)
	{
		res = btime - atime + day;
	}
	else
	{
		res = (day - atime) + btime;
	}

	int h = res / 60;
	int m = res % 60;
	cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m;


	

	return 0;
}