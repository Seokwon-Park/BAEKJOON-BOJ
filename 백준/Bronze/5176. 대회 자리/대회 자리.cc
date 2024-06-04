#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k;
	cin >> k;
	while (k--)
	{
		int p, m;
		cin >> p >> m;
		vector<bool> v(m + 1);
		int res = 0;
		for (int i = 0; i < p; i++)
		{
			int n;
			cin >> n;
			if (!v[n])
			{
				v[n] = true;
			}
			else
				res++;
		}
		cout << res << '\n';

	}


	return 0;
}
