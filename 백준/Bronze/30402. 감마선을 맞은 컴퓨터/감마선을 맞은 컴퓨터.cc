#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string ans;
	for(int i = 0; i< 15; i++)
		for (int j = 0; j < 15; j++)
		{
			char c;
			cin >> c;
			if (c == 'w') ans = "chunbae";
			if (c == 'b') ans = "nabi";
			if (c == 'g')ans = "yeongcheol";
		}
	cout << ans;

	return 0;
}