#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int m, n;
	cin >> m >> n;
	vector<bool> state(n + 1, true);
	state[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (!state[i]) continue; // false면 어차피 이전에 나온 수의 배수에서 처리됨.
		for (int j = i * 2; j <= n; j += i)
		{
			state[j] = false;
		}

		
	}
	for (int i = m; i <= n; i++)
	{
		if (state[i]) cout << i << '\n';
	}

	return 0;
}