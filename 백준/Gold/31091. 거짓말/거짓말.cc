#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int v[500005];
int pf[500005];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			v[0] += 1;
			v[x] -= 1;
		}
		else
		{
			v[-x+1] += 1;
			v[n + 1] -= 1;
		}
	}

	vector<int> ans;
	
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			pf[i] = v[i];
		}
		else
		{
			pf[i] = pf[i - 1] + v[i];
		}
		if (pf[i] == i)
		{
			ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans)
	{
		cout << i << ' ';
	}


	return 0;
}
