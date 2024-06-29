#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	char v[256];
	v['I'] = 'E';
	v['E'] = 'I';
	v['S'] = 'N';
	v['N'] = 'S';
	v['T'] = 'F';
	v['F'] = 'T';
	v['J'] = 'P';
	v['P'] = 'J';

	for (auto& c : s)
	{
		c = v[c];
	}
	cout << s;

	return 0;
}