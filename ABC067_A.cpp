#include <cstdio>
#include <iostream>
using namespace std;

/*
問題文
すぬけくんは 3 匹のヤギにクッキーを渡したいです。

すぬけくんは A 枚のクッキーが入った缶と、B 枚のクッキーが入った缶を持っています。 
すぬけくんは A,B,A+B のいずれかの枚数のクッキーをヤギたちに渡すことができます。

3 匹のヤギが同じ枚数ずつ食べられるようにクッキーを渡すことが可能かどうか判定してください。

制約
1≤A,B≤100
A,B はいずれも整数

test input:
4 5
output:
Possible

test input:
1 1
output :
Impossible

*/
int main(){
	int a,b;
	cin >> a >> b;
	/*
	受け入れ条件：
	1、a+bは3の倍数
	2、aは3の倍数
	3、bは3の倍数
	*/
	if((a+b)%3==0||a%3==0||b%3==0) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}