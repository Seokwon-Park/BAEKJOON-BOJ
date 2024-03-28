#include<iostream>
#include<string>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, n;
	cin >> a >> b >> c >> n;

	if (n % a == 0 || n % b == 0 || n % c == 0)
	{
		cout << 1;
		return 0;
	}
	for (int i = n / a; i >= 0; i--)
		for (int j = n / b; j >= 0; j--)
			for (int k = n / c; k >= 0; k--)
			{
				if (i * a + j * b + k * c == n)
				{
					cout << 1;
					return 0;
				}
			}

	cout << 0;

	return 0;
}