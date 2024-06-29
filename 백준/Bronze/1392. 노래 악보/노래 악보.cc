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

	int n, q;
	cin >> n >> q;

	vector<int> v(10005);
	int st = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = st; j < st+m; j++)
		{
			v[j] = i+1;
		}
		st += m;
	}

	for (int i = 0; i < q; i++)
	{
		int k;
		cin >> k;
		cout << v[k] << '\n';
	}

	return 0;
}
