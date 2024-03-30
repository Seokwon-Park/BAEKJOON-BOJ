#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int calc(int a, int b, char op)
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	if (op == '/')
		return a / b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k1, k2, k3;
	char o1, o2;
	cin >> k1 >> o1 >> k2 >> o2 >> k3;
	
	int a = calc(calc(k1, k2, o1), k3, o2);
	int b = calc(k1, calc(k2, k3, o2), o1);
	if (a > b)
		cout << b << '\n' << a;
	else
		cout << a << '\n' << b;


	return 0;
}