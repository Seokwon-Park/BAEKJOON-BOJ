#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

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

	int res = v[1] - v[0];
	for (int i = 1; i < n; i++)
	{
		res = gcd(res, v[i] - v[i-1]);
	}

	set<int> ans;
	for (int i = 1; i*i <= res; i++)
	{
		if (res % i == 0)
		{
			if(i != 1)
				ans.insert(i);
			ans.insert(res / i);
		}
	}

	for (auto i : ans)
		cout << i << ' ';

	return 0;
}