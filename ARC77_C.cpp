#include <cstdio>
#include <iostream>
#include <stack>
#include <stdlib.h>
#define INF 100000
using namespace std;
int point_a = 0;
int point_b = -1;
int* A = (int*)malloc(INF*sizeof(int));
int* B = (int*)malloc(INF*sizeof(int));
stack<int> st;
int array[512345];
int a[212345];


/*
長さ n の数列 a1,…,an が与えられます。 空の数列 b に対して、以下の操作を n 回行うことを考えます。

i 回目には

数列の i 番目の要素 ai を b の末尾に追加する。
b を逆向きに並び替える。
この操作をしてできる数列 b を求めて下さい。

*/

/*
1 2 3 4 5 6
6 4 2 1 2 5

1 2 3 4
4 2 1 3

中心向两边递增 左边是偶数位  右边是奇数位
所以初始设left=n right=left+1






*/
void pushback(int b){
	while(b>=0)
	{
		st.push(B[b]);
		b--;
	}
}

void popto(int b,int t){
	while(t > 0){
		b++;
		B[b] = st.top();
		st.pop();
		t--;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
    /*这方法过不了4个例子以外的*/ 
    /*
	for(int i = 1; i <= n; i++){
		
		
		for(int j = 0; j < i; j++){
			st.push(A[j]);
		}
		for(int j = 0; j < i; j++){
			A[j] = st.top();
			st.pop();
		}
	

		}
	*/
	int left = 212345, right = left + 1;
	for(int i = 0; i < n; i++){
		if(i%2 == (n-1)%2){
			array[left--] = a[i];
		}
		else{
			array[right++] = a[i];
		}
	}
	

for(int i = left + 1; i < right; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	
}