#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	//
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < n * 2 - 3; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';
	//
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n * 2 - 3 - 2 * (i + 1); j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	for (int j = 0; j < n - 1; j++)
		cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; j++)
		cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; j++)
		cout << ' ';
	cout << '*';
	cout << '\n';

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < n - i - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < 1 + 2 * i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	//
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < n * 2 - 3; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	//

	return 0;
}