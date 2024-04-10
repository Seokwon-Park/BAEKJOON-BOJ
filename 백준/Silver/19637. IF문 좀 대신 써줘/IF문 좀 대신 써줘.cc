#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v;
	vector<string> name;
	for (int i = 0; i < n; i++)
	{
		string str;
		int n;
		cin >> str >> n;
		v.push_back(n);
		name.push_back(str);
	}
	while (m--)
	{
		int k;
		cin >> k;
		int ix = lower_bound(v.begin(), v.end(), k) - v.begin();
		cout << name[ix] << '\n';
	}

	return 0;
}