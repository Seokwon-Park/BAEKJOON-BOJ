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
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	if (n >= a)
	{
		cout << "Watermelon";
	}
	else if (n >= b)
	{
		cout << "Pomegranates";
	}
	else if (n >= c)
	{
		cout << "Nuts";
	}
	else
	{
		cout << "Nothing";
	}

	return 0;
}