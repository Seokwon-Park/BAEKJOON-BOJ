#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

string shift(string a)
{
	int n = a.size();
	int carry = 0;
	string ret(n, '0');
	for (int i = n-1; i >= 0; i--)
	{
		int anum = a[i] - '0';
		ret[i] = ((anum * 2 + carry) % 10)+'0';
		carry = (anum * 2 + carry) / 10;
	}
	if (carry)
		ret = '1' + ret;
	return ret;
}

void hanoi(int a, int b, int k)
{
	if (k == 1) // base condition
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(a, 6 - a - b, k - 1);
	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, k - 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string num = "1";
	for (int i = 0; i < n; i++)
	{
		num = shift(num);
	}

	(*num.rbegin())--;

	cout << num << '\n';
	if (n <= 20)
		hanoi(1, 3, n);

	return 0;
}