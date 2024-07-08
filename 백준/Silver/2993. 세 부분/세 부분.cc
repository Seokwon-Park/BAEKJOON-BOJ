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

	string s;
	cin >> s;
	int sz = s.size();

	string ans = string(sz, 'z');

	for (int i = 1; i <= sz - 2; i++)
	{
		string a = s.substr(0, i);
		reverse(a.begin(), a.end());
		for (int j = i+1; j <= sz - 1; j++)
		{
			string b = s.substr(i, j-i);
			reverse(b.begin(), b.end());

			string c = s.substr(j);
			reverse(c.begin(), c.end());

			string res = a + b + c;
			ans = min(ans, res);

		}
	}

	cout << ans;



	return 0;
}