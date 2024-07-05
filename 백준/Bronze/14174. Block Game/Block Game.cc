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

	vector<int> v(26, 0);
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		vector<int> va(26, 0);
		vector<int> vb(26, 0);
		for (int j = 0; j < a.size(); j++)
		{
			va[a[j] - 'a']++;
		}
		for (int j = 0; j < b.size(); j++)
		{
			vb[b[j] - 'a']++;
		}

		for (int i = 0; i < 26; i++)
		{
			v[i] += max(va[i], vb[i]);
		}
	}

	for (int i : v)
		cout << i << '\n';

	return 0;
}
