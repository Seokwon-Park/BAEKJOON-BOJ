#include<iostream>
#include<string>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
					cout << '*';
				else
					cout << ' ';
			}
			else
			{
				if (j % 2 == 0)
					cout << ' ';
				else
					cout << '*';
			}
		}
		cout << '\n';
	}

	return 0;
}