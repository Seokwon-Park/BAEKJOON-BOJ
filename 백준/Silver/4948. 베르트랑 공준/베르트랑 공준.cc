#include <bits/stdc++.h>

using namespace std;

bool sosu[300000];

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(sosu, sosu + 300000, true);

	for (int i = 2; i * i < 300000; i++)
	{
		if (!sosu[i]) continue;
		for (int j = i * i; j < 300000; j += i)
		{
			sosu[j] = false;
		}
	}

	int input;
	while (true)
	{
		cin >> input;
		if (!input) break;
		int count = 0;
		int n = input;
		int n2 = input * 2;
		for (int i = n+1; i <= n2; i++)
		{
			if (sosu[i]) count++;
		}
		cout << count << '\n';
	}

	return 0;
}