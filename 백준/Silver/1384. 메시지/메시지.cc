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
	
	int ix = 1;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		vector<string> name(n);
		vector<vector<char>> pn(n, vector<char>(n-1));
		for (int i = 0; i < n; i++)
		{
			cin >> name[i];
			for (int j = 0; j < n - 1; j++)
			{
				cin >> pn[i][pn[i].size() - 1 - j];
			}
		}

		cout << "Group " << ix++ << '\n';
		bool nobody = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 2; j >=0; j--)
			{
				if (pn[i][j] == 'N')
				{
					cout << name[(i + j + 1) % n] << " was nasty about " << name[i] << '\n';
					nobody = false;
				}
			}
		}
		if (nobody)
			cout << "Nobody was nasty\n";
		cout << '\n';
	}


	return 0;
}