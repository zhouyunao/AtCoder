#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
問題文
AtCoDeer君は、赤、緑、青色のカードを持っています。
それぞれのカードには 1 以上 9 以下の整数が書かれており、赤色のカードには r、緑色のカードには g、青色のカードには b が書かれています。
3 つのカードを左から順に赤、緑、青色の順に並べ、左から整数を読んだときにこれが 4 の倍数であるか判定しなさい。

制約
1≤r,g,b≤9

test input:
4 3 2

output:
YES

test input:
2 3 4

output:
NO

*/

int main(){
	int r;
	int g;
	int b;
	cin >> r >> g >> b;
	int ans = r * 100 + g * 10 + b ;
	if(ans%4 == 0) cout <<"YES" << endl;
	else cout << "NO" << endl;
}
