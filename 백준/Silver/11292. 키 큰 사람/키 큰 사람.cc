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

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		vector<pair<double,string>> v;
		for (int i = 0; i < n; i++)
		{
			string name;
			double k;
			cin >> name >> k;
			v.push_back({ k, name });
		}
		double mx = max_element(v.begin(), v.end())->first;
		for (int i = 0; i < n; i++)
		{
			if (v[i].first == mx)
				cout << v[i].second << ' ';
		}
		cout << '\n';
	}

	return 0;
}
