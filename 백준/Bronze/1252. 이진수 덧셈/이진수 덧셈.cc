#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string bitadd(string n1, string n2)
{
	// 0으로 시작하는 입력일 경우.
	int ix = 0;
	while (n1[ix] == '0')ix++;
	if (ix == n1.size())
		n1 = "0";
	else
		n1 = n1.substr(ix);

	ix = 0;
	while (n2[ix] == '0')ix++;
	if (ix == n2.size())
		n2 = "0";
	else
		n2 = n2.substr(ix);

	if (n1 == "0" && n2 == "0")
		return "0";

	int n = max(n1.size(), n2.size());


	n1 = string(n - n1.size(), '0') + n1;
	n2 = string(n - n2.size(), '0') + n2;

	string res(n, '0');
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int a = n1[i] - '0';
		int b = n2[i] - '0';
		int result = a ^ b;
		res[i] = (result ^ carry) + '0';
		carry = (result & carry) | (a & b);
	}

	if (carry)
		res = '1' + res;
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	cout << bitadd(a, b);

	return 0;
}
