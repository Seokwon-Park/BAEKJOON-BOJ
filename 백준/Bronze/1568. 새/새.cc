#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int song = 1;
	int cnt = 0;
	while (n > 0)
	{
		if (n >= song)
		{
			n -= song;
		}
		else
		{
			song = 1;
			n -= song;
		}
		song++;
		cnt++;
	}
	cout << cnt;

	return 0;
}