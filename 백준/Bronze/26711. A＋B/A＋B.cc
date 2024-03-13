#include <bits/stdc++.h>

using namespace std;

string Add(string& a, string& b)
{
	int n = max(a.size(), b.size());
	
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;

	int carry = 0;
	string result(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int aa = a[i] - '0';
		int bb = b[i] - '0';
		int res = aa + bb + carry;
		carry = res / 10;
		result[i] = (res % 10)+'0';
	}
	if (carry)
		result = '1' + result;

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;

	cout << Add(a, b);

	return 0;
}