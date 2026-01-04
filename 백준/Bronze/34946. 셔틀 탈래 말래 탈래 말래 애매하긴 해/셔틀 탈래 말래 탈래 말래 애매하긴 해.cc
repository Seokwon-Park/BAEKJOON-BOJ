#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a + b <= d && c <= d)
	{
		cout << "~.~";
	}
	else if(a+b <= d)
	{
		cout << "Shuttle";
	}
	else if (c <= d)
	{
		cout << "Walk";
	}
	else
	{
		cout << "T.T";
	}


	return 0;
}
