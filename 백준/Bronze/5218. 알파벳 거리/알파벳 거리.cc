#include<iostream>
#include<string>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while(tc--)
	{
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++)
		{
			int x = a[i];
			int y = b[i];
			if (y >= x)
				cout << y - x << ' ';
			else
				cout << y + 26 - x << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}