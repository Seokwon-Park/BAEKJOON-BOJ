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
	int x, y;
	cin >> x >> y;
	cin >> n;
	int xy = x * y;

	for (int i = 1; i <= n; i++)
	{
		if (i % x == 0 && i%y ==0)
		{
			cout << "FizzBuzz";
		}
		else if (i % x == 0)
		{
			cout << "Fizz";
		}
		else if (i % y == 0)
		{
			cout << "Buzz";
		}
		else
			cout << i;
		cout << '\n';
	}

	return 0;
}