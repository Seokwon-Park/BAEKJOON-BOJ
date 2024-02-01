#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	vector<int> f(n);
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}

	sort(f.begin(), f.end());
	for (int i : f)
	{
		if (i <= l)
			l++;
	}
	cout << l;

	return 0;
}