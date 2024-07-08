#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin.ignore();
	string s;
	getline(cin, s);
	sort(s.begin(), s.end());

	string res = "";
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
			res.push_back(' ');
		else if (v[i] <= 26)
			res.push_back('A' + v[i] - 1);
		else
			res.push_back('a' + v[i] - 27);
	}
	sort(res.begin(), res.end());
	if (res == s)
		cout << 'y';
	else
		cout << 'n';

	return 0;
}