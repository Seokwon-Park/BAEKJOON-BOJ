#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int e, s, m;
	cin >> e >> s >> m;

	//int g = gcd(gcd(e, s), m);
	int l = lcm(lcm(15, 28), 19);

	e %= 15; s %= 28; m %= 19;
	for (int i = 1; i <= l; i++)
	{
		if (i % 15 == e && i % 28 == s && i % 19 == m)
		{
			cout << i;
			break;
		}
	}

	return 0;
}
