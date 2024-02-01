#include<bits/stdc++.h>
using namespace std;

int count_five(int n)
{
	int cnt = 0;
	for (long long i = 5; i <= n; i *= 5)
	{
		cnt += n / i;
	}

	return cnt;
}

int count_two(int n)
{
	int cnt = 0;
	for (long long i = 2; i <= n; i*=2)
	{
		cnt += n / i;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//cout << count_two(n) << '\n';
	//cout << count_five(n) << '\n';
	//cout << count_two(m) << '\n';
	//cout << count_five(m) << '\n';
	//cout << count_two(n-m) << '\n';
	//cout << count_five(n-m) << '\n';

	int two = count_two(n) - count_two(m) - count_two(n-m);
	int five = count_five(n) - count_five(m) - count_five(n-m);

	cout << min(two, five);

	return 0;
}