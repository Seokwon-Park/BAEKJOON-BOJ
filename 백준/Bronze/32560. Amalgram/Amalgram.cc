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

	string a;
	string b;
	cin >> a >> b;

	vector<int> va(26, 0), vb(26, 0);

	for (auto c : a)
	{
		va[c - 'a']++;
	}

	for (auto c : b)
	{
		vb[c - 'a']++;
	}

	vector<int> v(26, 0);
	for (int i = 0; i < 26; i++)
	{
		int k = max(va[i], vb[i]);
		for (int j = 0; j < k; j++)
		{
			cout << (char)('a' + i);
		}
	}
	

	return 0;
}