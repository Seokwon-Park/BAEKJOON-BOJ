#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		string n;
		cin >> n;
		if (n == "0") break;
		if ((n[n.size() - 1] - '0') % 2 != 0) // 홀수면 무조건 안됨.
		{
			cout << "TENTE NOVAMENTE\n";
			continue;
		}

		string tmp = "";
		for (int i = 0; i < n.size(); i++)
		{
			tmp += n[i];
			int tmpnum = stoi(tmp);
			while (tmpnum >= 42)
			{
				tmpnum -= 42;
			}
			tmp = to_string(tmpnum);
		}
		if (tmp == "0")
		{
			cout << "PREMIADO\n";
		}
		else
		{
			cout << "TENTE NOVAMENTE\n";
		}


	}

	return 0;
}