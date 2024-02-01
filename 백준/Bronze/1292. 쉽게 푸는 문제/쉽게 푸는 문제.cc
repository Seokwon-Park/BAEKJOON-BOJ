#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	vector<int> pfsum(1005, 0);
	int i = 1;
	int ix = 1;
	while (true)
	{
		for (int j = 1; j <= i; j++)
		{
			pfsum[ix] = pfsum[ix - 1] + i;
			ix++;
			if (ix > 1004) 
				break;
		}
		if (ix > 1004) 
			break;
		i++;
	}

	cout << pfsum[b] - pfsum[a-1];

	return 0;
}