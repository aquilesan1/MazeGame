#include <iostream>

using namespace std;


// Draw the map
char map[7][7] = {{'-','-','-','-','-','-','-'},
				{'|',' ',' ',' ',' ',' ',' '},
				{'|',' ','-','-','-','-','|'},
				{'|',' ','|','<',' ',' ','|'},
				{'|',' ','-','-','-',' ','|'},
				{'|',' ',' ',' ',' ',' ','|'},
				{'-','-','-','-','-','-','-'}};
				
int currPos[2];

void display(){
	
	for (int i = 0; i < 7; i++){
		
		for (int j = 0; j < 7; j++){
			
			// Display map
			cout << map[i][j];
		}
		
		cout << '\n';
	}
}

void checker(){
	
	if (currPos[0] == 3 && currPos[1] == 3){
		
		cout << "You Win!\nPress x to leave game.\n";
	}
}

int main(){
	
	char button;
	
	// have to display movement keys
	cout << "Welcome to Maze Game!\nMovement keys are:\n       ^\n<- 'a' | 'w' | 's' -> 'd'\n             `\n";
	
	display();
	
	currPos[0] = 1;
	currPos[1] = 6;
	
	map[currPos[0]][currPos[1]] = '*';
	
	display();
	
	while (button != 'x'){
	
		cin >> button;
	
		if (button == 'a'){
			
			// if a is hit move left one, keep vertical the same
			map[currPos[0]][currPos[1]] = ' ';
			
			currPos[1] -= 1;
			
			map[currPos[0]][currPos[1]] = '*';
			
			checker();
			
		} else if (button == 's'){
			
			map[currPos[0]][currPos[1]] = ' ';
			
			currPos[0] += 1;
			
			map[currPos[0]][currPos[1]] = '*';
			
			checker();
			
		} else if (button == 'd'){
			
			map[currPos[0]][currPos[1]] = ' ';
			
			currPos[1] += 1;
			
			map[currPos[0]][currPos[1]] = '*';
			
			checker();
			
		} else if (button == 'w'){
			
			map[currPos[0]][currPos[1]] = ' ';
			
			currPos[0] -= 1;
			
			map[currPos[0]][currPos[1]] = '*';
			
			checker();
		}
		
		display();
	}
	
	return 0;
}