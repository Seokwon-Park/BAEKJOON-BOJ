#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int mid = (vec.size() - 1) / 2;

	cout << vec[mid];


	return 0;
}
