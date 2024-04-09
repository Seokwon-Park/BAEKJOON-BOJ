#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> si(n+1);
		vector<int> ai(n+1);
		for (int i = 0; i < m; i++)
		{
			int a, b, p, q;
			cin >> a >> b >> p >> q;
			si[a] += p;
			ai[a] += q;
			si[b] += q;
			ai[b] += p;
		}
		vector<double> w(n + 1);
		for (int i = 1; i <= n; i++)
		{
			if (si[i] == 0 && ai[i] == 0)
			{
				w[i] = 0.0;
				continue;
			}
			double s2 = si[i] * si[i];
			double a2 = ai[i] * ai[i];
			w[i] = s2 / (s2 + a2);
		}
		cout << (ll)(*max_element(w.begin() + 1, w.end()) * 1000) << '\n';
		cout << (ll)(*min_element(w.begin() + 1, w.end()) * 1000) << '\n';
	}	
	return 0;
}