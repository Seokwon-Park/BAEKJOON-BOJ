#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(6);
	
	for (int i = 0; i < 6; i++)
	{
		cin >> v[i];
	}

	int t, p;
	cin >> t >> p;

	int res = 0;
	for (int i = 0; i < 6; i++)
	{
		int tmp = v[i] /t;
		if (v[i] % t != 0)
		{
			tmp++;
		}
		res += tmp;
	}

	cout << res << '\n';
	cout << n / p << ' ' << n % p;



	return 0;
}