#include <cstdio>
#include <iostream>　　//swap
using namespace std;
int T[51];
int check[51];
int max_p = 0;

/*
void dfs(int A[], int k, int i, int n,int z){
	int x = 0;
	if(k<= 0) return;

	else {

		
		int y;
		for(int t = i; t <= n; t++){
			y = A[t];
			dfs(A, k-1, t+1, n, z+y);
			
			if(z+y>max_p) max_p = z+y;
		}
			 
		
		return;
	}
}
*/


/*
問題文
すぬけくんは N 本の棒を持っています。 i 番目の棒の長さは li です。

すぬけくんは K 本の棒を選んでつなげて、ヘビのおもちゃを作りたいです。

ヘビのおもちゃの長さは選んだ棒たちの長さの総和で表されます。 ヘビのおもちゃの長さとしてありうる長さのうち、最大値を求めなさい。

制約
1≤K≤N≤50
1≤li≤50
li は整数

test input:
5 3
1 2 3 4 5

output:
12

test input:
15 14
50 26 27 21 41 7 42 35 7 5 5 36 39 1 45

output:
386

*/


/*
バブルソート　降順
*/
void sort(int A[],int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if(A[j] > A[j-1]) swap(A[j], A[j-1]);
		}
	}
}

int main(){
	int N,K;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> T[i];
	}

	int i;
	/*
	ソートのあと、前のK個の和を求めればいい
	*/
	int ans = 0;
	sort(T, N);
	for(int t = 0; t < K; t++){
		ans += T[t];
		
	}


	/*
	for(i = 0; i <= N-K; i++){
		dfs(T,K,0,N,0);
	
		
	}
	*/

	cout << ans << endl;


}