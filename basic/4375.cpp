#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	while (cin >> n)
	{
		int answer = 1;
		long long one = 1;
		while (one % n != 0)
		{
			one = one * 10 + 1;
			one %= n;
			answer++;
		}

		cout << answer << '\n';
	}
	return 0;
}
