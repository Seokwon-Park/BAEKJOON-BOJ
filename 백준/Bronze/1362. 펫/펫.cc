#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc = 1;
	while (1)
	{
		int o, w;
		cin >> o >> w;
		if (o == 0 && w == 0) break;
		while (1)
		{
			char cmd;
			int n;
			cin >> cmd >> n;
			if (cmd == '#' && n == 0) break;
			if (cmd == 'E')
			{
				w -= n;
			}
			else
			{
				if (w > 0)
					w += n;
			}
		}
		cout << tc++ << ' ';
		if (o < w * 2 && w < o * 2)
			cout << ":-)";
		else if (w <= 0)
			cout << "RIP";
		else
			cout << ":-(";
		cout << '\n';
	}

	return 0;
}
