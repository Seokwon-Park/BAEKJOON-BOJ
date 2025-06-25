#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s, tmp;
		cin >> s >> tmp;
		int sbit = 0;
		int tmpbit = 0;
		for (auto c : s)
		{
			sbit |= 1 << (c - 'a');
		}
		for (auto c : tmp)
		{
			tmpbit |= 1 << (c - 'a');
		}

		cout << ((sbit | tmpbit) == sbit ? "YES" : "NO") << '\n';
		
	}


	return 0;
}