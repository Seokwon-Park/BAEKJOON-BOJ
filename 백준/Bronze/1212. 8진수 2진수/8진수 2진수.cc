#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string ei;
	cin >> ei;
	string bi = "";
	for (char c : ei)
	{
		int n = c - '0';
		int b = 4;
		for (int i = 0; i < 3; i++)
		{
			char res = (n / b) + '0';
			if (bi.empty() && res == '0')
			{
				n %= b;
				b /= 2;
				continue;
			}
			bi.push_back(res);
			n %= b;
			b /= 2;
			
		}
	}

	if (!bi.length())
		cout << 0;
	else
		cout << bi;

	return 0;
}