#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> m;

	// 0: 1win 1: 2win -1: draw;
	m["RR"] = -1;
	m["RS"] = 0;
	m["RP"] = 1;
	m["SR"] = 1;
	m["SS"] = -1;
	m["SP"] = 0;
	m["PR"] = 0;
	m["PS"] = 1;
	m["PP"] = -1;

	
	string p1, p2;
	while (1)
	{
		cin >> p1 >> p2;
		vector<int> v(2, 0);
		if (p1 == "E" && p2 == "E")break;
		for (int i = 0; i < p1.size(); i++)
		{
			string key = "";
			key += p1[i];
			key += p2[i];
			int val = m[key];
			if (val != -1)
			{
				v[val]++;
			}
		}
		cout << "P1: " << v[0] << '\n';
		cout << "P2: " << v[1] << '\n';

	}

	return 0;
}