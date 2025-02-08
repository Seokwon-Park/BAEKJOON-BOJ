#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	for (auto c : s)
	{
		if (isalpha(c))
		{
			v[c - 'a']++;
		}
	}
	cout << *max_element(v, v + 26);

	return 0;
}
