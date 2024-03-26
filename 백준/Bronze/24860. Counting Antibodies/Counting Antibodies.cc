#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll vk, jk, vr, jr, vh, dh, jh;
	cin >> vk >> jk;
	cin >> vr >> jr;
	cin >> vh >> dh >> jh;
	
	cout << ((vk * jk) + (vr * jr)) * vh * dh * jh;

	return 0;
}