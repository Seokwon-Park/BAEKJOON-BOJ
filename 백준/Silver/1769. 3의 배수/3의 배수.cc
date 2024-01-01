#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string n;
	cin >> n;
	int cnt = 0;
	string copy = n;
	int sum = copy.length() > 1 ? 0 : stoi(n);
	while (copy.length() > 1)
	{
		sum = 0;
		cnt++;
		for (auto c : copy)
		{
			sum += c-'0';
		}
		if (sum < 10)
		{
			break;
		}
		else
		{
			copy = to_string(sum);
		}
	}

	cout << cnt << '\n';
	if (sum % 3 == 0)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}