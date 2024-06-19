#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int f[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		f[v[i]]++;
	}
	
	vector<int> ans(n);
	for (int i = n-1; i >= 0 ; i--)
	{
		if (s.empty())
		{
			ans[i] = -1;
			s.push(v[i]);
		}
		else
		{
			if (f[v[i]] < f[s.top()])
			{
				ans[i] = s.top();
				s.push(v[i]);
			}
			else
			{
				while (!s.empty() && f[v[i]] >= f[s.top()])
				{
					s.pop();
				}

				if (s.empty())
				{
					ans[i] = -1;
				}
				else
				{
					ans[i] = s.top();
				}
				s.push(v[i]);
			}
		}
	}

	for (int i : ans)
		cout << i << ' ';

	return 0;
}
