#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int T, N, K;
string str;
vector<int> temp(7);
vector<int> res;

void go() {
	char temp = str[str.size() - 1];
	for (int i = str.size() - 2; i >= 0; i--) {
		str[i + 1] = str[i];
	}
	str[0] = temp;
}

int main()
{
	int test;
	scanf("%d", &T);
	for (test = 1; test <= T; test++) {
		scanf("%d %d", &N, &K);
		cin >> str;
		int size = str.size() / 4;
		int t = size;
		int sum = 0;
		for (int t = 1; t <= size; t++) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < size; j++) {
					if (str[j + (size * i)] >= 'A') {
						temp[j] = str[j + (size * i)] - 55;
					}
					else {
						temp[j] = str[j + (size * i)] - '0';
					}
					int mult = pow(16, size - j - 1);
					temp[j] = temp[j] * mult;
					sum += temp[j];
				}
				res.push_back(sum);
				sum = 0;
				temp.assign(7, 0);
			}
			go();
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());

		cout << "#" << test << ' ' << res[res.size() - K] << '\n';
		res.clear();
	}

	return 0;
}
