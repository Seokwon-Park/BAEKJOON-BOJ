#include <bits/stdc++.h>

using namespace std;

int swift[100005];
int sema[100005];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n;

	int input, answer = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		swift[i] = swift[i - 1] + input;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		sema[i] = sema[i - 1] + input;
	}

	for (int i = 1; i <= n; i++)
	{
		if (sema[i] == swift[i])
		{
			answer = i;
		}
	}

	cout << answer;
	
	return 0;
}