#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for(int t = 1; t<= tc; t++)
	{
		int n;
		cin >> n;
		vector<int> v(n * 2);
		for (int i = 0; i < n * 2; i++)
		{
			cin >> v[i];
		}

		vector<int> ans;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0) continue;
			int discnt = v[i];
			int findVal = 0;
			if (discnt % 3 != 0)
				continue;
			else
				findVal = discnt / 3 * 4;
			for (int j = 1; j < v.size(); j++)
			{
				if (v[j] == findVal)
				{
					v[j] = 0;
					ans.push_back(v[i]);
					break;
				}
			}
		}
		cout << "Case #" << t << ": ";
		for (auto i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	

	return 0;
}