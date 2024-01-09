#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;
	string k;
	cin >> k;

	int answer = 0;
	
	for (int i = 0; i < m;i++)
	{
		int rn = 0;
		if (k[i] == 'I')
		{
			while (i < m && (k[i + 1] == 'O' && k[i + 2] == 'I'))
			{
				rn++;
				i += 2;
			}
			if (rn >= n)
			{
				answer += rn - n + 1;
			}
		}
	}

	cout << answer;

	return 0;
}