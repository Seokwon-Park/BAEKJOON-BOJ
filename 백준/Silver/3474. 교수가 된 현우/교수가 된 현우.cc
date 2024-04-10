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
		ll n;
		cin >> n;
		ll five = 0;
		for (int i = 5; i <= n; i *= 5)
		{
			five += n / i;
		}
		cout << five << '\n';
		
	}
	

	return 0;
}
