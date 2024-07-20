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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> vv;

	for (int i = 0; i < n; i++)
	{
		if (vv.empty())
		{
			vv.push_back(v[i]);
		}
		else
		{
			bool find = false;
			for (int j = 0; j < vv.size(); j++)
			{
				if (v[i] > vv[j])
				{
					vv[j] = v[i];
					find = true;
					break;
				}
			}
			if (!find)
			{
				vv.push_back(v[i]);
			}
		}
	}
	cout << vv.size();

	

	return 0;
}