#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int GRID_SIZE = 10; // Grid dimensions

struct Position {
    int x, y;
};

class WormRobot {
private:
    Position pos;
    vector<vector<char>> grid;

public:
    WormRobot() {
        // Initialize grid with empty spaces
        grid.resize(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
        
        // Set initial position
        pos.x = GRID_SIZE / 2;
        pos.y = GRID_SIZE / 2;
        grid[pos.x][pos.y] = 'W'; // 'W' represents the worm
    }

    void displayGrid() {
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void move(char direction) {
        // Clear previous position
        grid[pos.x][pos.y] = '.';

        switch (direction) {
            case 'U': if (pos.x > 0) pos.x--; break;
            case 'D': if (pos.x < GRID_SIZE - 1) pos.x++; break;
            case 'L': if (pos.y > 0) pos.y--; break;
            case 'R': if (pos.y < GRID_SIZE - 1) pos.y++; break;
            default: cout << "Invalid move!" << endl; return;
        }

        // Update position
        grid[pos.x][pos.y] = 'W';
        displayGrid();
    }
};

int main() {
    srand(time(0));
    WormRobot worm;
    worm.displayGrid();

    char moves[] = {'U', 'D', 'L', 'R'}; // Possible moves
    for (int i = 0; i < 10; ++i) { // Move 10 times
        char move = moves[rand() % 4];
        cout << "Moving: " << move << endl;
        worm.move(move);
    }
    return 0;
}

