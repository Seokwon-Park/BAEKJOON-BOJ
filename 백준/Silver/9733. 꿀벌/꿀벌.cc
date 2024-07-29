#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

double q[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	map<string, int> m;
	int total = 0;
	while (cin >> s)
	{
		m[s]++;
		total++;
	}

	vector<string> v = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };
	for (auto str : v)
	{
		cout << str << ' ' << m[str] << ' ' << fixed << setprecision(2) << (double)m[str] / total << '\n';
	}
	cout << "Total " << total << " 1.00";

	return 0;
}