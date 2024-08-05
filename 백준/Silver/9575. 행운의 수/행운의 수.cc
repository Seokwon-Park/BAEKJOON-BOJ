#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> v;

void func(string s)
{
	if (s.size() >= 6)
		return;
	if (!s.empty()) v.push_back(stoi(s));
	func(s + '5');
	func(s + '8');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	func("");

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> n;
		vector<int> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		cin >> n;
		vector<int> c(n);
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
		}
		sort(c.begin(), c.end());
		vector<int > ab;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				ab.push_back(a[i] + b[j]);
			}
		}
		
		int ans = 0;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < ab.size(); j++)
			{
				if (binary_search(c.begin(), c.end(), v[i] - ab[j]))
				{
					ans++;
					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}