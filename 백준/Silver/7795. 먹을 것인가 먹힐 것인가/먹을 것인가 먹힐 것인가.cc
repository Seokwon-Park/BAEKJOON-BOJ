#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());

		int answer = 0;
		for (auto i : a)
		{
			for (int j = 0; j < m; j++)
			{
				if (i > b[j])
				{
					answer += m - j;
					break;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}