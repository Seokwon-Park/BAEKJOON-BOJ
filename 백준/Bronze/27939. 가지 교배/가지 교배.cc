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

	int n;
	cin >> n;
	vector<char> gaji(n);
	for (int i = 0; i < n; i++)
	{
		cin >> gaji[i];
	}

	int m, k;
	cin >> m >> k;
	bool isWhite = false;
	for (int i = 0; i < m; i++)
	{
		bool res = 0;
		for (int j = 0; j < k; j++)
		{
			int ix;
			cin >> ix;
			bool curgaji = (gaji[ix - 1] == 'P');
			res |= curgaji;
		}
		if (!res)
		{
			isWhite = true;
		}
	}

	cout << (isWhite ? 'W' : 'P');

	return 0;
}

