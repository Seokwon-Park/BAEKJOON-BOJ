#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		
		bool odd = false;
		if (n % 2)
		{
			odd = true;
		}

		int sq = sqrt(n);
		bool isSq = false;
		if (sq* sq == n)
		{
			isSq = true;
		}

		if (!odd && !isSq)
		{
			cout << "EMPTY";
		}
		else
		{
			cout << (odd ? "O" : "") << (isSq ? "S" : "");
		}
		cout << '\n';
	}


	return 0;
}