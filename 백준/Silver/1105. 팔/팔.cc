#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string l, r;

	cin >> l >> r;

	int answer = 0;
	if (l.length() != r.length())
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < r.length(); i++)
	{
		if (l[i] != r[i]) break;
		if (l[i] == '8' && r[i] == '8')
			answer++;
	}

	cout << answer;
	

	return 0;
}
