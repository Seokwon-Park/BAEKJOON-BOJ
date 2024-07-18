#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
	
int fast_pow(int n, int exp)
{
	if (exp == 0) return 1;
	int res = fast_pow(n, exp / 2);
	if (exp % 2 == 0)
	{
		return res * res;
	}
	else
	{
		return res * res * n;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int b, n;
		cin >> b >> n;
		if (b == 0 && n == 0) break;
		int a = 0;
		int res = 0;
		do{
			res = fast_pow(++a, n);
		} while (res < b);
		
		int le = fast_pow(a - 1, n);
		int gt= res;

		if (abs(le - b) < abs(gt - b))
			cout << a - 1;
		else
			cout << a;
		cout << '\n';
	}


	return 0;
}