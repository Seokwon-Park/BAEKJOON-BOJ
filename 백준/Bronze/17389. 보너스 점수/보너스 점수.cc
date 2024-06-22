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

	int n;
	string s;
	cin >> n >> s;
	int bonus = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'X')
		{
			bonus = 0;
		}
		else
		{
			total += i + 1;
			total += bonus;
			bonus++;
		}
	}
	cout << total;

	return 0;
}