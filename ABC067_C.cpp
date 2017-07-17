#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long T[200001];


/*
問題文
すぬけくんとアライグマは N 枚のカードの山を作りました。カードの山の上から i 番目のカードには
整数 ai が書かれています。

N 枚のカードを分け合うことにしました。 すぬけくんがカードの山の上から何枚かのカードを取ったあと、
アライグマは残ったカード全てを取ります。 このとき、すぬけくんもアライグマも 1 枚以上のカードを取る必要があります。

すぬけくんとアライグマが持っているカードに書かれた数の総和をそれぞれ x,y として、|x−y| を最小化したいです。 
|x−y| としてありうる値の最小値を求めなさい。

制約
2≤N≤2×105
−10^9≤ai≤10^9
ai は整数

test input:
6
1 2 3 4 5 6
output:
1

test input:
2
10 -10
output:
20


*/
int main(){
	int N;
	/*
	制限−10^9≤ai≤10^9のためここlong longを使う
	最小値は最初一番大きくに置く

	long longが表示できるの64bitの数字つまり2の64乗
	*/
	long long add_all = 0;
	long long min_p = 1000000000000000000LL;
	

	/*
	まず全部の和を求める
	*/
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> T[i];
		add_all += T[i]; 
	}

	/*
	次牌山の上の部分の和を求める
	配列に反映すると、前i個の和
	add_all - leftによる残った部分の和を求める
	でadd_all - 2*leftは左右両方の差になります
	*/
	long long left = 0;
	for(int i = 0; i <= N-2; i++){
		left += T[i];
		long long tmp = add_all-left-left;
		if(min_p > abs(tmp)) min_p = abs(tmp);

	}

	cout << min_p << endl;
}