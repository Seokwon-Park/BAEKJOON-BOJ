#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, b;
	cin >> n >> b;
	string answer;

	while(n!= 0)
	{
		int tmp = n % b;
		n /= b;
		if (tmp < 10)
		{
			answer+=('0' + tmp);
		}
		else
		{
			tmp -= 10;
			answer+=('A' + tmp);
		}

	}
	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;

}
