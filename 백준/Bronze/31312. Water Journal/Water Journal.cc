#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	bool aa = false;
	bool bb = false;
	for(int i = 0; i< n-1;i++)
	{
		int x;
		cin >> x;
		if (x == a) aa = true;
		if (x == b) bb = true;
	}
	if (!aa && !bb) cout << -1;
	else if (!aa) cout << a;
	else if (!bb) cout << b;
	else
	{
		for (int i = a; i <= b; i++)
		{
			cout << i << '\n';
		}
	}


	return 0;
}
