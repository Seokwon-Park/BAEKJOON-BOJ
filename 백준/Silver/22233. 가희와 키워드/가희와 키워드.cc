#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	unordered_map<string, bool> um;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		um[s] = true;
	}
	for (int j = 0; j < m; j++)
	{
		string k;
		cin >> k;
		istringstream iss(k);
		string tmp;
		while (getline(iss, tmp, ','))
		{
			if (um.find(tmp) != um.end())
			{
				um.erase(tmp);
			}
		}
		cout << um.size() << '\n';
	}

	return 0;
}