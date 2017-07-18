#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
//int tree[100001][100001];   too large
vector<int> tree[100005];
int checkbox[100005];
int snuke[100005];
int fennec[100005];
int N;
/*
問題文
フェネックとすぬけくんがボードゲームで遊んでいます。

このボードゲームには 1 番から N 番までの番号がついた N 個のマスと、マスどうしをつなぐ N−1 本の道が存在しています。 
ai 番のマスと bi 番のマスは i 番目の道を介して隣り合っています。どの 2 つのマスも隣接するマスをいくつか辿って必ず辿り着くことが可能です。
すなわち、グラフ理論の言葉を用いると、マスと道から構成されるグラフは木です。

はじめに 1 番のマスは黒く、N 番のマスは白く塗られています。その他のマスはまだ色が塗られていません。 
先手のフェネックと後手のすぬけくんは残りのマスに交互に色を塗ります。 自分の手番において、2 人はそれぞれ以下のような行動を行います。

フェネック：黒く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 黒く 塗る。
すぬけくん：白く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 白く 塗る。
手番のプレイヤーがマスに色を塗ることができなかったとき、敗者となります。フェネックとすぬけくんが最適に行動したとき勝者はどちらか判定してください。

制約
2≤N≤105
1≤ai,bi≤N
与えられるグラフは木

test input:
7
3 6
1 2
3 1
7 4
5 7
1 4

output:
Fennec

test input:
4
1 4
4 2
2 3

ouput:
Snuke

*/



/*
Fennec側から考えるとdfsで、1からほかのノードまでの距離を求める
Snuke側から考えるとdfsで、Nからほかのノードまでの距離を求める
*/
void dfs(int start, int dist, int member[]){

	checkbox[start] = 1;
	member[start] = dist;
	for(int i = 0; i < tree[start].size(); i++){
		if(tree[start][i] != 0 && checkbox[tree[start][i]] == 0){
			dfs(tree[start][i], dist+1, member);
		}
	}
	return;
}

void judge(int A[], int B[]){
	int fennec_s = 0;
	int snuke_s = 0;
	for(int i = 1; i <= N; i++){
		/*
		両方最適を実行するため、先手有利
		スタートポイントからの距離が同じだとすると先手のものにする。

		*/
		if(A[i] <= B[i]) fennec_s++;
		else snuke_s++;
	}
	/*
	先手Fennecのため
	１、もし同点の場合、次動けなくなるのはFennec
	２、Fennec点数が大きいと、自明Fennecの勝ち
	３、少ない場合は同じ自明Snukeの勝ち

	*/
	if(fennec_s > snuke_s) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
}



int main(){
	cin >> N;
	for(int i = 1; i <= N-1; i++){
		int x, y;
		cin >> x >> y;
		//tree[x][y] =1; tree[y][x] = 1;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	for(int i = 1; i <= N; i++){
		checkbox[i] = 0;
		snuke[i] = 0;
		fennec[i] = 0;
	}



	dfs(1, 0, fennec);
	for(int i = 1; i <= N; i++){
		checkbox[i] = 0;
	}
	dfs(N, 0, snuke);
	/*
	cout << endl;
	for(int i = 1; i <= N; i++){
		cout << fennec[i] << " " << snuke[i] << endl;
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
	*/
	judge(fennec, snuke);

}