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
	map<string, bool> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		bool isExist = false;
		for (int i = 0; i < s.size(); i++)
		{
			string tmp = s;
			tmp = tmp.substr(i) + tmp.substr(0, i);
			if (m.find(tmp) != m.end())
			{
				isExist = true;
				break;
			}
		}
		if (!isExist)
			m[s] = true;
	}

	cout << m.size();

	return 0;
}