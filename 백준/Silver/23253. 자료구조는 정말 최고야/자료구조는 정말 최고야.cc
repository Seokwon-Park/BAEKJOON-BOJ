#include <bits/stdc++.h>

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
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		vector<int> v(k);
		for (int j = 0; j < k; j++)
		{
			cin >> v[j];
			if (j > 0)
			{
				if (v[j - 1] < v[j])
				{
					cout << "No";
					return 0;
				}
			}
		}
	}
	cout << "Yes";

	return 0;
}