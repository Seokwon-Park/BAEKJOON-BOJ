#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;
	int newa = ~a + 1;

	bitset<32> x(a), y(newa);
	int answer = 0;
	for (int i = 0; i < 32; i++)
	{
		if (x[i] != y[i])
			answer++;
	}

	cout << answer;

	return 0;
}