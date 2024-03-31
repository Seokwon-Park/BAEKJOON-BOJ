#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	int cs = 1;
	while (1)
	{
		cin >> a >> b;
		if (a == "END" && b == "END")break;
		cout << "Case " << cs++ << ": ";
		if (a.size() != b.size())
		{
			cout << "different\n";
			continue;
		}
		vector<int> aa(26, 0), bb(26, 0);
		for (int i = 0; i < a.size(); i++)
		{
			aa[a[i] - 'a']++;
			bb[b[i] - 'a']++;
		}
		if (aa == bb)
			cout << "same";
		else
			cout << "different";
		cout << '\n';
	}


	return 0;
}