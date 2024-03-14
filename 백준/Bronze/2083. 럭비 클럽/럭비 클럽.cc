#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (1)
	{
		string nm;
		int age, wei;
		cin >> nm >> age >> wei;
		if (nm == "#") break;
		cout << nm;
		if (age > 17 || wei >= 80)
			cout << " Senior\n";
		else
			cout << " Junior\n";
	}
	return 0;
}