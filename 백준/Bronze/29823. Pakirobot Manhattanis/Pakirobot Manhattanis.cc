#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, e, s, w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len;
	cin >> len;
	string str;
	cin >> str;
	
	for (auto c : str)
	{
		if (c == 'N')
			n++;
		else if (c == 'E')
			e++;
		else if (c == 'S')
			s++;
		else
			w++;
	}

	cout<< abs(n - s) + abs(e - w);

	return 0;
}