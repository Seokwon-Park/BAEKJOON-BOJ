#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

using bigint = vector<int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc = 1;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		int n1 = 3 * n;
		int n2 = 0;
		if (n1 % 2)
			n2 = (n1 + 1) / 2;
		else
			n2 = n1 / 2;
		int n3 = n2 * 3;
		int n4 = n3 / 9;

		cout << tc++ << ". " << (n1 % 2 ? "odd " : "even ") << n4 << '\n';
	}



	return 0;
}