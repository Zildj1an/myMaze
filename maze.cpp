#include <iostream>
using namespace std;

typedef struct{
	int row;
	int column;
} tCell;


void maze(bool myMaze[][3],tCell solution[], int k, int n, bool marks[][3]);
void treatSolution(tCell solution[], int k); //display
bool isValid(bool myMaze[][3], tCell c, int n, const bool marks[][3]); //matches with the exit
bool isSolution(tCell pos, int n); //in the exit(n-1,n-1)
tCell nextDirection(int dir, tCell pos);

const int MAX = 50000;

int main(){

	bool myMaze[3][3]; //for instances
	bool marks[3][3];
	tCell solution[MAX];

	// 3 x 3 maze

	myMaze[0][0] = true; //Starting point
	myMaze[0][1] = true;
	myMaze[0][2] = false; //false if wall
	myMaze[1][0] = false;
	myMaze[1][1] = true;
	myMaze[1][2] = false;
	myMaze[2][0] = false;
	myMaze[2][1] = true;
	myMaze[2][2] = true; //Exit

	//everything unmarked
	for(int i = 0; i < 3; ++i){
		for(int s = 0; s < 3; ++s){
			marks[i][s] = false;
		}
	}

	tCell startPoint;
	startPoint.row = startPoint.column = 0;
  solution[0] = startPoint;
	maze(myMaze,solution,0,3,marks);

 return 0;
}


//n is the size of the matrix
//k is the position in the solution
void maze(bool myMaze[][3],tCell solution[], int k, int n, bool marks[][3]){
	for (int dir = 0; dir < 4; dir++)
	{
		solution[k] = nextDirection(dir, solution[k-1]);
		if (isValid(myMaze, solution[k], n, marks)) {
			if (isSolution(solution[k],n))
				treatSolution(solution, k);
			else{
				// mark
				marks[solution[k].row][solution[k].column] = true;
				maze(myMaze, solution, k + 1, n, marks);
				//unmark
				//marks
			}
		}
	}
}

bool isValid(bool myMaze[][3], tCell c, int n, const bool marks[][3]){
	return c.row >= 0 && c.column >= 0 && c.row < n && c.column < n
	&& myMaze[c.row][c.column] && !marks[c.row][c.column];
}

bool isSolution(tCell pos, int n){
	return pos.row == n - 1 && pos.column == n - 1;
}

tCell nextDirection(int dir, tCell pos){
	switch (dir) {
	case 0: ++ pos.column; break;
	case 1: ++ pos.row; break;
	case 2: -- pos.column; break;
	case 3: -- pos.row; break;
	default: break;
	}
return pos;
}


void treatSolution(tCell solution[], int k){
		for(int i = 0; i <= k; ++i){
			cout << "row -> " << solution[i].row << " ";
			cout << "column ->" << solution[i].column << endl;
		}
}
