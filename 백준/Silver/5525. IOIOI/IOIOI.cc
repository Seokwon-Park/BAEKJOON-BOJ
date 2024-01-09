#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string pn = "I";
	for (int i = 0; i < n; i++)
	{
		pn += "OI";
	}
	int m;
	cin >> m;
	string k;
	cin >> k;

	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		if (k[i] == 'I')
		{
			if (pn == k.substr(i, pn.length()))
			{
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}