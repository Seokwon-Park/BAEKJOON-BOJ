#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ix(4);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		ix[v[i]]++;
	}


	int u, d;
	cin >> u >> d;
	if (ix[1] > u || ix[2] > d)
	{
		cout << "NO";
		return 0;
	}

	string left = string(u - ix[1], 'U') + string(d - ix[2], 'D');

	string s(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 1)
		{
			s[i] = 'U';
		}
		else if (v[i] == 2)
		{
			s[i] = 'D';
		}
		else
		{
			s[i] = left.back();
			left.pop_back();
		}
	}

	cout << "YES\n";
	cout << s;

	return 0;
}
