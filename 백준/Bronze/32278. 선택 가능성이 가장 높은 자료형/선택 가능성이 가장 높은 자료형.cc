#include<bits/stdc++.h>

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

	ll n;
	cin >> n;
	if (n >= SHRT_MIN && n <= SHRT_MAX)
		cout << "short";
	else if (n >= INT_MIN && n <= INT_MAX)
		cout << "int";
	else
		cout << "long long";

	return 0;
}

