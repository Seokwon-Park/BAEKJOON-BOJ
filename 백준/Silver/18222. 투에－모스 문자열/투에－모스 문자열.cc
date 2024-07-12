#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	ll n;
	cin >> n;

	n--;
	ll k = 0;
	while (n)
	{
		if (n % 2) k++;
		n /= 2;
	}

	if (k % 2)
		cout << 1;
	else
		cout << 0;
	




	return 0;
}
