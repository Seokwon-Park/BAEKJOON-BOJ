#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int dp[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int m;
	cin >> m;
	vector<int> b(m);
	
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}       
	
	int ast = 0;
	int bst = 0;
	vector<int> ans;
	while (1)
	{
		int mx = -1;
		int nast = 0;
		int nbst = 0;
		for (int i = ast; i < n; i++)
		{
			for (int j = bst; j < m; j++)
			{
				if (a[i] == b[j])
				{
					if (mx < a[i])
					{
						mx = a[i];
						nast = i+1;
						nbst = j+1;
					}
				}
			}
		}
		if (mx == -1)break;
		ans.push_back(mx);
		ast = nast;
		bst = nbst;
	}

	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';


	return 0;
}