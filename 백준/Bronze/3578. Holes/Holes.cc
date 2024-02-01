#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h;
	cin >> h;
	
	string ans = "";
	if (h == 0)
	{
		cout << 1;
		return 0;
	}
	else if (h == 1)
	{
		cout << 0;
		return 0;
	}
	else if (h % 2 == 0)
	{
		int n = h / 2;
		while (n--)
		{
			ans += '8';
		}
	}
	else
	{
		ans += "4";
		int n = h / 2;
		while (n--)
		{
			ans += '8';
		}
	}

	cout << ans;

	return 0;
}