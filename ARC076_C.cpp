#include <cstdio>
#include <iostream>
using namespace std;

/*
	問題文
すぬけ君は、犬を N 匹と猿を M 匹飼っています。すぬけ君は、この N+M 匹を一列に並べようと思っています。

文字通り犬猿の仲の犬たちと猿たちを仲直りさせたいすぬけ君は、犬同士、または猿同士が隣り合うところができないように並べようと思っています。

このような並べ方は何通りあるでしょうか。犬と猿は 109+7 以上の数を理解できないので、並べ方の個数を 109+7 で割ったあまりを求めてください。 ただし、犬同士、また猿同士は互いに区別します。また、左右が反転しただけの列も異なる列とみなします。

	制約
1≦N,M≦105
	

	input:
	2 2
	output:
	8

	input:
	3 2
	output:
	12

	input:
	1 8
	output:
	0

	inpnut:
	100000 100000
	output:
	530123477



*/

int main(){
	int a,b;
	cin >> a >> b;

	/*|a-b| >= 2 时候没有符合结果*/
	if(a-b >= 2 || b-a >= 2) cout << "0" << endl;


	/*|a-b| == 1 时候ans = aAa * bAb  */
	else if(a-b == 1 || b-a==1) {
		long long p_a = 1;
		long long p_b = 1;
		for(int i = 1; i <= a; i++){
			p_a = (i*p_a)%1000000007;
		}
		for(int i = 1; i <=b; i++)
			p_b = (i*p_b)%1000000007;

		cout << (p_a*p_b)%1000000007 << endl;
		}
	/*a==b 时候ans= aAa * aAa * 2   */
	else if(a==b) {
		long long p = 1;
		long long q = 1;
		for(int i = 1; i <= a;i++){
			p= (i*p) % 1000000007;
			


		}
		p = (p*p) % 1000000007;
		p = (p*2)% 1000000007;
		cout << p << endl;
	}

		


}