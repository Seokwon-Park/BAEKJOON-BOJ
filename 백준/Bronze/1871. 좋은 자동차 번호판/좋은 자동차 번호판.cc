#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		int num = stoi(str.substr(4, 4));
		str = str.substr(0, 3);
		
		int alpha = 0;
		int tmp = 1;
		for (int i = 2; i >= 0; i--)
		{
			alpha += (str[i] - 'A') * tmp;
			tmp *= 26;
		}

		if (abs(alpha - num) <= 100)
		{
			cout << "nice\n";
		}
		else
		{
			cout << "not nice\n";
		}

	}
		
	return 0;
}