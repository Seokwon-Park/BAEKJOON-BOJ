#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
			
		vector<int> v(n);
		vector<bool> chk(n, false);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (n == 1)
		{
			cout << "Jolly\n";
			continue;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int tmp = abs(v[i + 1] - v[i]);
			if (tmp >= n)break;
			chk[tmp] = true;
		}
		int res = count(chk.begin() + 1, chk.end(), true);
		if (res == n - 1)
			cout << "Jolly";
		else
			cout << "Not jolly";
		cout << '\n';
	}
	

	return 0;
}