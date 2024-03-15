#include <bits/stdc++.h>
//#include <Windows.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

std::string unicodeToUTF8(int unicode) {
	std::string utf8_string;

	//ex) utf-8 => '가'
	// 0xAC00 = 1010 1100 0000 0000 (44032);
	// (>> 12 = 1010)
	// 0xE0 = 1110 0000
	// 1110 1010 = 234 
	
	// (>> 6 = 1010 1100 00) & 0011 1111
	// = 10 1011 0000 & 00 0011 1111 
	// = 00 0011 0000
	// 0x80 = 1000 0000
	// 0011 0000 | 1000 0000
	// = 1011 0000 = 176

	// 1010 1100 0000 0000 & 0000 0000 0011 1111;
	// = 0000 0000 0000 0000;
	// 0x80 | 0000 0000
	// = 1000 0000 = 128
	// utf-8 '가' = 0xEA + 0xB0 + 0x80
	utf8_string += static_cast<char>(0xE0 | (unicode >> 12));
	utf8_string += static_cast<char>(0x80 | ((unicode >> 6) & 0x3F));
	utf8_string += static_cast<char>(0x80 | (unicode & 0x3F));

	return utf8_string;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	n--;

	//chcp 65001;
	//::SetConsoleOutputCP(65001);
	cout << unicodeToUTF8(n+ 44032);

	return 0;
}