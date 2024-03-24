#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		string bit;
		int tmp = n;
		while (tmp)
		{
			bit.push_back(tmp % 2 + '0');
			tmp /= 2;
		}
		for (int i =0; i < bit.size(); i++)
		{
			if (bit[i] == '1')
				cout << i << ' ';
		}
		cout << '\n';
	}	
		

	return 0;
}