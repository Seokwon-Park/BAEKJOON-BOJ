#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n;
string s;

int calc(int a, int b, char op)
{
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
}

int func(int k, int prev_val, bool prev_used)
{
	if (k == n / 2)
	{
		return prev_val;
	}
	int b = s[(k + 1) * 2] - '0';
	char op = s[k * 2 + 1];
	int res = calc(prev_val, b, op);

	if (prev_used) return res;
	int res1 = func(k + 1, res, false);
	int res2 = INT_MIN;
	if (!prev_used)
	{
		res2 = calc(prev_val, func(k + 1, b, true), op);
		if (k + 2 <= n / 2)
		{
			res2 = func(k + 2, res2, false);
		}
	}
	return max(res1, res2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> n;
	cin >> s;

	cout << func(0, s[0] - '0', false);

	return 0;
}