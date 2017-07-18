#include <cstdio>
#include <iostream>
using namespace std;
int INF = 99999;
/*
問題文
snuke 君は自転車を買いに来ました。 snuke 君はすでに買う自転車を決めたのですが、
その自転車にはベルが付いていないため、 自転車とは別にベルも買う必要があります。

snuke 君は安全意識が高いので、ベルをどちらの手でも鳴らせるよう、
両方のハンドルに 1 つずつ 付けることにしました。

お店にあるベルは 3 種類で、それぞれ a円、 b円、 c円です。 
この 3 つのうち、異なる 2 つのベルを選んで買うときの、値段の合計の最小値を求めて下さい。

制約
1≤a,b,c≤10000
a,b,c は整数

test input:
700 600 780

output:
1300

test input:
1000 1000 1000

output:
2000
*/

/*
三つの引数（ひきすう）を持つMIN関数
*/
int min_p(int a, int b, int c){
	if(a < INF) INF = a;
	if(b < INF) INF = b;
	if(c < INF) INF = c;

	return INF; 
}

/*
a+b  a+c  b+cの組み合わせの最小値を求める
*/
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << min_p(a+b,a+c,b+c) << endl;

}