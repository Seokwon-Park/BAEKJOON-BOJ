#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	vector<string> q;
	int ans = 0;
	bool isWrong= true;
	for (auto c : s)
	{
		isWrong = true;
		if (c == 'q')
		{
			q.push_back("q");
			isWrong = false;
			ans = max(ans, (int)q.size());
		}
		else if (c == 'u')
		{
			for (int i = 0; i < q.size(); i++)
			{
				if (q[i].back() == 'q')
				{
					q[i].push_back(c);
					isWrong = false;
					break;
				}
			}
		}
		else if (c == 'a')
		{
			for (int i = 0; i < q.size(); i++)
			{
				if (q[i].back() == 'u')
				{
					q[i].push_back(c);
					isWrong = false;
					break;
				}
			}
		}
		else if (c == 'c')
		{
			for (int i = 0; i < q.size(); i++)
			{
				if (q[i].back() == 'a')
				{
					q[i].push_back(c);
					isWrong = false;
					break;
				}
			}
		}
		else if (c == 'k')
		{
			for (int i = 0; i < q.size(); i++)
			{
				if (q[i].back() == 'c')
				{
					q.erase(q.begin()+i);
					isWrong = false;
					break;
				}
			}
		}
		if (isWrong) break;
	}


	if (!q.empty() || isWrong)
		cout << -1;
	else
		cout << ans;

	return 0;
}