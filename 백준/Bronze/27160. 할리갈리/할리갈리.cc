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
	
	map<string, int>m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		int k;
		cin >> s >> k;
		m[s] += k;
	}

	for (auto [a, b] : m)
	{
		if (b == 5)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}