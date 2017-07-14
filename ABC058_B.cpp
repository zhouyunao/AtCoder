#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*

問題文

  すぬけ君は新しくできたプログラミングコンテストに会員登録しました。 登録に使ったパスワードを覚えておく自信が無かったすぬけ君は、 
  手元の紙にパスワードをメモしておくことにしました。 ただし、そのままメモをすると誰かにパスワードを盗まれてしまうかもしれないので、 
  文字列の偶数番目の文字と奇数番目の文字をそれぞれ別々の紙にメモしておくことにしました。
  パスワードの奇数番目の文字だけを順番を変えずに取り出した文字列 O と、 偶数番目の文字だけを順番を変えずに取り出した文字列 E 
  が与えられます。 すぬけ君のかわりにパスワードを復元してください。


  input:
  xyz
  abc

  output:
  xaybzc


*/


/*
	char * a = new char[1000];
	声明时要申请范围
	

	0 1 2 3
	x y z \0


\*/
int main(){
	char * a = new char[1000];
	char * b = new char[1000];

	cin >> a;
	cin >> b;

	int p_a = 0;
	int p_b = 0;
	int p_c = 1;
	char *c = new char[1000];

	while(a[p_a] != '\0' || b[p_b] != '\0'){
		if(p_c%2==1) {
			c[p_c] = a[p_a];
			p_a++;
		}
		else {
			c[p_c] = b[p_b];
			p_b++;
		}
		p_c++;
	}
	int t = 1;
	while(c[t] != '\0'){
		cout << c[t++];
	}
	cout << endl;
}