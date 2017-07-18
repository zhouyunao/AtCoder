#include <cstdio>
#include <iostream>
using namespace std;

/*
問題文
同じ文字列を 2 つ並べてできる文字列のことを偶文字列と呼ぶことにします。 
例えば、 xyzxyz や aaaaaa は偶文字列ですが、ababab や xyzxy は偶文字列ではありません。

アルファベットの小文字からなる偶文字列 S が与えられます。 
S の末尾の文字を 1 文字以上消して作れる偶文字列のうち、最も長い偶文字列の長さを求めて下さい。 
与えられる入力では、条件を満たす 1 文字以上の文字列が存在することが保証されています。

制約
2≤|S|≤200
S は小文字のアルファベットのみからなる偶文字列である。
S に対して、条件を満たす 1 文字以上の文字列が存在する。


test input:
abaababaab

output:
6
(abaaba)

test input:
xxxx

output:
2
(xx)

test input:
akasakaakasakasakaakas

ouput:
14
(akasakaakasaka)
*/

int main(){
	char * ch = new char(205);
	cin >> ch;
	int i = 0;
	/*
	文字列の長さiを求める
	最後の \0 までloop
	例：　abc\0
	*/
	while(ch[i] != '\0'){
		i++;
	}
	/*
	長さ一時保存
	*/
	int N = i;
	//cout << i << endl;

	
	/*
	長さNから0までデクリメントして
	{
	奇数の場合　continueで略する
	偶数の場合　インデックス　t-1 と　t-i/2-1　の
	文字を照合して　不一致の場合 flagを0に置く
	最後条件（　flag==1　と　i<N　）が満たしたら　break
	}
	*/
	for(;i >= 0; i--){
		if(i%2 == 1) {continue;}
		else {
			int flag = 1;
			for(int t = i; t >= i/2+1; t--){
				if(ch[t-1] != ch[t-i/2-1]) flag = 0;
				//cout << ch[t-1] << endl;
				//cout << ch[t-i/2-1] << endl;
			}
			if(flag == 1 && i != N) break;
			//cout << i << endl;
		}
	}

	cout << i << endl;
}