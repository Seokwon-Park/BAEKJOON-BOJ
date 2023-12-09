#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int cnt= 0;

	string tmp;
	for (auto itr = str.begin(); itr != str.end(); itr++)
	{
		tmp += *itr;
		cnt++;
		if (cnt == 10)
		{
			cout <<tmp << '\n';
			tmp.clear();
			cnt = 0;
		}
	}

	if (tmp.length() > 0)
	{
		cout << tmp << '\n';
	}

	return 0;
}