#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	int a = 0, b = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char input;
			cin >> input;
			if (input == '1')
				a++;
			else
				b++;
		}
	}

	cout << min(a, b);

	return 0;
}