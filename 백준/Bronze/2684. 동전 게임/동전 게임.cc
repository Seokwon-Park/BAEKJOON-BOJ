#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, int>m;
	m["TTT"] = 0;
	m["TTH"] = 1;
	m["THT"] = 2;
	m["THH"] = 3;
	m["HTT"] = 4;
	m["HTH"] = 5;
	m["HHT"] = 6;
	m["HHH"] = 7;

	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<int> res(8, 0);
		string s;
		cin >> s;
		for (int i = 0; i < s.size() - 2; i++)
		{
			res[m[string(s.begin() + i, s.begin() + i + 3)]]++;
		}
		for (auto i : res)
			cout << i << ' ';
		cout << '\n';

	}

	return 0;
}