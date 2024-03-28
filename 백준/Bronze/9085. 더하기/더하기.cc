#include<iostream>
#include<string>

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
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			sum += m;
		}
		cout << sum << '\n';
	}

	return 0;
}