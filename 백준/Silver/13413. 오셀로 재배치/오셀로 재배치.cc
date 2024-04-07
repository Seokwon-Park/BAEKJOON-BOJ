#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

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
		string a, b;
		cin >> a >> b;
		int wrongw = 0;
		int wrongb = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				if (a[i] == 'W')
					wrongw++;
				else
					wrongb++;
			}
		}
		//cout << wrongw << ' ' << wrongb << '\n';
		int cnt = 0;

		int swapped= min(wrongw, wrongb);
		cnt += swapped;
		wrongw -= swapped;
		wrongb -= swapped;
		if (wrongw != 0) cnt += wrongw;
		else if (wrongb != 0) cnt += wrongb;
		cout << cnt << '\n';
	}

	return 0;
}