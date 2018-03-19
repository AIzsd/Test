#include<iostream>
using namespace std;
static int tile = 1;
static int board[BOARD_SZ][BOARD_SZ] = { 0 };
void chess_board(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
		return;
	int t = tile++;   //L型骨牌号
	int sz = size / 2;    //对棋盘进行分割 
	//覆盖左上角子棋盘
	if (dr < tr + sz && dc < tc + sz)  
		chess_board(tr, tc, dr, dc, sz);
	else{
		board[tr + sz - 1][tc + sz - 1] = t;
		chess_board(tr, tc, tr + sz - 1, tc + sz - 1, sz);
	}
	//覆盖右上角子棋盘 
	if (dr < tr + sz && dc >= tc + sz)   
		chess_board(tr, tc + sz, dr, dc, sz);
	else{
		board[tr + sz - 1][tc + sz] = t;
		chess_board(tr, tc + sz, tr + sz - 1, tc + sz, sz);
	}

	//覆盖左下角子棋盘 
	if (dr >= tr + sz && dc < tc + sz)  
		chess_board(tr + sz, tc, dr, dc, sz);
	else{
		board[tr + sz][tc + sz - 1] = t;
		chess_board(tr + sz, tc, tr + sz, tc + sz - 1, sz);
	}

	//覆盖右下角子棋盘  
	if (dr >= tr + sz && dc >= tc + sz)  
		chess_board(tr + sz, tc + sz, dr, dc, sz);
	else{
		board[tr + sz][tc + sz] = t;                       //标记一个假设的特殊点  
		chess_board(tr + sz, tc + sz, tr + sz, tc + sz, sz);   //递归该部分  
	}
}

void print_chess_board()
{
	   //左对齐  
	for (int i = 0; i<BOARD_SZ; ++i){
		for (int j = 0; j<BOARD_SZ; ++j){
			cout.width(3);    //打印宽度为3  
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	chess_board(0, 0, 0, 1, 4);
	print_chess_board();
	getchar();
	return 0;
}

