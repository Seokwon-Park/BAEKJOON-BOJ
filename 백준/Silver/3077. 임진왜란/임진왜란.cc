#include<bits/stdc++.h>

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

	int n;
	cin >> n;
	unordered_map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s] = i;
	}

	vector<string> v(n);
	for(int i= 0; i< n;i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (m[v[i]] < m[v[j]])
				ans++;
		}
	}

	int total = n * (n - 1) / 2;


	cout << ans << '/' << total;

	return 0;
}

