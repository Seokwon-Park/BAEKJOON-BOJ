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
	ll n;
	cin >> n;

	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size()-1-i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


	return 0;
}