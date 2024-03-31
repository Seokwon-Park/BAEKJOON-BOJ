#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mp[256];
	mp['A'] = 3;
	mp['B'] = 2;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['E'] = 4;
	mp['F'] = 3;
	mp['G'] = 1;
	mp['H'] = 3;
	mp['I'] = 1;
	mp['J'] = 1;
	mp['K'] = 3;
	mp['L'] = 1;
	mp['M'] = 3;
	mp['N'] = 2;
	mp['O'] = 1;
	mp['P'] = 2;
	mp['Q'] = 2;
	mp['R'] = 2;
	mp['S'] = 1;
	mp['T'] = 2;
	mp['U'] = 1;
	mp['V'] = 1;
	mp['W'] = 1;
	mp['X'] = 2;
	mp['Y'] = 2;
	mp['Z'] = 1;


	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int acur = 0, bcur = 0;

	vector<int> v;
	while (acur < n && bcur < m)
	{
		v.push_back(mp[a[acur++]]);
		v.push_back(mp[b[bcur++]]);
	}
	while (acur < n)
		v.push_back(mp[a[acur++]]);
	while (bcur < m)
		v.push_back(mp[b[bcur++]]);

	while (v.size() > 2)
	{
		vector<int> tmp(v.size()-1);
		for (int i = 0; i < v.size() - 1; i++)
		{
			tmp[i] = (v[i] + v[i + 1])%10;
		}
		v = tmp;
	}
	cout << (v[0] == 0? "" : to_string(v[0])) << v[1] << '%';

	return 0;
}