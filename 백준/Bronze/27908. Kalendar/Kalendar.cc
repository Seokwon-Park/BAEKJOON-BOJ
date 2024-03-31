#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	cout << '+';
	for (int i = 0; i < 21; i++)
		cout << '-';
	cout << '+' << '\n';
	int cur = 1;
	d--;
	string line = "";
	while (d--)
	{
		for (int i = 0; i < 3; i++)
			line += '.';
	}
	while (cur <= n)
	{
		string num = to_string(cur);
		num = string(3 - num.size(), '.')+num;
		line += num;
		cur++;
		if (line.size() == 21)
		{
			cout << '|' << line << '|' << '\n';
			line = "";
		}
	}
	if (!line.empty())
	{
		line = line + string(21 - line.size(), '.');
		cout << '|' << line << '|' << '\n';
	}


	cout << '+';
	for (int i = 0; i < 21; i++)
		cout << '-';
	cout << '+' << '\n';


	return 0;
}