#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> call;

	int answer = 0;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		call[input]++;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		call[input]++;
		if (call[input] > 1)answer++;
	}

	cout << answer << '\n';
	for (auto str : call)
	{

		if (str.second > 1)
			cout << str.first << '\n';
	}

	return 0;
}