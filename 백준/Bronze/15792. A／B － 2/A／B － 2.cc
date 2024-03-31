#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int q = a / b;
	int r = a % b;
	string fp = "";
	for (int i = 0; i < 1005; i++)
	{
		r *= 10;
		fp += (r / b) + '0';
		r = r % b;
	}

	cout << q << '.' << fp;

	return 0;
}