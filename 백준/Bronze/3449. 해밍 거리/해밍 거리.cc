#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int v[256];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string a, b;
		cin >> a >> b;
		int res = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				res++;
		}

		cout << "Hamming distance is " << res << ".\n";
	}

	return 0;
}