#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

void kill(vector<string>& v, vector<bool>& isAlive, char charToKill, int ix)
{
	for (int j = 1; j < v.size(); j++)
	{
		if (isAlive[j] && v[j][ix] == charToKill)
		{
			isAlive[j] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		vector<string> v(n+1);
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}


		int k = v[1].size();
		vector<bool> isAlive(n + 1, true);
		isAlive[0] = false;
		// PRS;
		for (int i = 0; i < k; i++)
		{
			set<char> res;
			for (int j = 1; j <= n; j++)
			{
				if (isAlive[j])
				{
					res.insert(v[j][i]);
				}
			}
			string tmp(res.begin(), res.end());
			if (res.size() == 3 || res.size() == 1)
				continue;
			else
			{
				if (tmp == "PR")
				{
					kill(v, isAlive, 'R', i);
				}
				else if (tmp == "RS")
				{
					kill(v, isAlive, 'S', i);
				}
				else
				{
					kill(v, isAlive, 'P', i);
				}
			}
		}

		if (count(isAlive.begin(), isAlive.end(), true) == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				if (isAlive[j])
				{
					cout << j;
					break;
				}
			}
		}
		else
		{
			cout << 0;
		}

		cout << '\n';

	}

	return 0;
}