#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s = "baby sukhwan tururu turu very cute tururu turu in bed tururu turu baby sukhwan";
	istringstream iss(s);
	string tmp;
	vector<string> song;
	while (getline(iss, tmp, ' '))
	{
		song.push_back(tmp);
	}

	vector<int> Ru(14, 0);
	Ru[2] = 2;
	Ru[3] = 1;
	Ru[6] = 2;
	Ru[7] = 1;
	Ru[10] = 2;
	Ru[11] = 1;

	int n;
	cin >> n;
	n-= 1;//0-indexed
	int repeat = n / 14;
	int ix = n % 14;
	if (Ru[ix] == 0)
		cout << song[ix];
	else
	{
		int repeatRu = repeat + Ru[ix];
		cout << "tu";
		if (repeatRu < 5)
		{
			for (int i = 0; i < repeatRu; i++)
			{
				cout << "ru";
			}
		}
		else
		{
			cout << "+ru*" << repeatRu;
		}
	}

	return 0;
}