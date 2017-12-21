/* This program generates certain possible moves available, but beware it is incomplete.
It does not generate killing / teleportation moves.
 */
#include <bits/stdc++.h>
using namespace std;

// please read about #define and typedef in c++ to completely understand this code

// below 4 #define(s) are used as constants in the program
#define BoardSize 12
#define WHITE 1
#define BLACK 0
#define EMPTY -1
// below 4 #define(s) are used for personal convenience of shortening the code to be written
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

// defining a new type which holds a pair of integers to represent a board cell
typedef pair<int, int> Position;
// defining another type which holds initial and final Position which represents a move
typedef pair<Position, Position> Move;

// for three horizontal directions available in every move
int dx[] = {-1, 0, 1};

/* Grid has 1 as white, 0 as black and -1 as empty cell */
int grid[BoardSize][BoardSize];
int me;
int opponent;

// checks of a (i,j) pair is within bounds of the Board for being a valid final position
bool bounds(int i, int j) {
	if(i>=0 && i<BoardSize && j>=0 && j<BoardSize) {
		return 1;
	}
	return 0;
}

vector<Move> getPossibleMoves(int player) {
	int dy = (player == WHITE)?1:-1;
	vector<Move> possibleMoves;

	for(int i=0;i<BoardSize;i++) {
		for(int j=0;j<BoardSize;j++) {

			// initial position of the move should have a pawn of current player
			if(grid[i][j] == player) {
				Position initial = mp(i, j);
				
				for(int k=0;k<3;k++) {
					
					Position final = mp(i+dy, j+dx[k]);
					if(bounds(final.fr, final.sc) && grid[final.fr][final.sc] == EMPTY) {
						/* this code is not computing all possible moves,
						it is not considering killing moves as well as teleportation moves */
						possibleMoves.pb(mp(initial, final));
					}
				}
			}
		}
	}

	return possibleMoves;
}

int main() {
	scanf("%d", &me);

	// ternary operator
	opponent = (me == WHITE)?BLACK:WHITE;
	
	for(int i=0;i<BoardSize;i++) {
		for(int j=0;j<BoardSize;j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	srand(time(NULL));

	vector<Move> possibleMoves = getPossibleMoves(me);
	int randomIndex = rand() % possibleMoves.size();
	Move randomMove = possibleMoves[randomIndex];
	printf("%d %d %d %d", randomMove.fr.fr, randomMove.fr.sc, randomMove.sc.fr, randomMove.sc.sc);

	return 0;
}
