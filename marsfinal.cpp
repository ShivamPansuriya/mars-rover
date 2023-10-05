#include <bits/stdc++.h>
using namespace std;

vector<char>directionfacing = {'N','E','S','W'};
vector<int>moveY = {1,0,-1,0};
vector<int>moveX = {0,1,0,-1};

// Interface for Rover Commands
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};


// Composite Pattern: Grid and Obstacles
class GridComponent {
public:
    virtual bool hasObstacle() const = 0;
    virtual ~GridComponent() {}
};

class Grid : public GridComponent {
public:
    Grid(int width, int height) : width(width), height(height), obstacles(width * height, false) {}

    bool hasObstacle() const override {
        return false;
    }

    void placeObstacle(int x, int y) {
        obstacles[x + y * width] = true;
    }

    bool hasObstacle(int x, int y) const {
        return obstacles[x + y * width];
    }

    bool isValidCoordinate(int x, int y){
        return x >= 0 && x < width && y >= 0 && y < height && !hasObstacle(x, y); 
    }
private:
    int width;
    int height;
    vector<bool> obstacles;
};


// Forward Command
class MoveForwardCommand : public Command {
public:
    MoveForwardCommand(int& x, int& y, int& index, Grid& grid) : x(x), y(y), index(index), grid(grid) {}

    void execute() override {
        // Implement obstacle detection logic here (not included in this example)
        int newX = x+moveX[index];
        int newY = y+moveY[index];
        // Assume obstacles are detected externally and handled before executing commands
        
        
        if(grid.isValidCoordinate(newX, newY) ){
            x = newX;
            y = newY;
        }
        
    }

private:
    int& x;
    int& y;
    int& index;
    Grid& grid;
};

// Turn Left Command
class TurnLeftCommand : public Command {
public:
    TurnLeftCommand(int& index) : index(index) {}

    void execute() override {
        index = (index-1)%4;
    }

private:
    int& index;
};

// Turn Right Command
class TurnRightCommand : public Command {
public:
    TurnRightCommand(int& index) : index(index) {}

    void execute() override {
        index = (index+1)%4;
    }

private:
    int& index;
};

// Mars Rover
class Rover {
public:
    Rover(int x, int y, char direction, Grid& grid) : x(x), y(y), direction(direction), grid(grid) {}

    void executeCommands(const string& commands) {
        for(auto val:directionfacing){
            if(val==direction)
                break;
            index++;
        }
        for (char command : commands) {
            Command* cmd = nullptr;
            if (command == 'M') {
                cmd = new MoveForwardCommand(x, y, index, grid);
            } else if (command == 'L') {
                cmd = new TurnLeftCommand(index);
            } else if (command == 'R') {
                cmd = new TurnRightCommand(index);
            }

            if (cmd) {
                cmd->execute();
                delete cmd;
            }
        }
    }

    void reportStatus() const {
        cout << "Current Position: (" << x << ", " << y << "), Facing: " << directionfacing[index] << endl;
    }

private:
    int x;
    int y;
    int index=0;
    char direction;
    Grid& grid;
};

int main() {
    int width,height;
    cout<<"Entre the size of width 'Width Height': ";
    cin>>width>>height;
    Grid grid(width, height);
    cout << "Entre the number of obstacle in a grid: ";
    int obstacleNumber,x,y;
    cin>>obstacleNumber;
    while(obstacleNumber--){
        cout<<"Enter the coordinate 'x y' of obstracle in grid: ";
        cin >> x >> y ;
        grid.placeObstacle(x, y);
    }
    cout <<"Enter the starting coordinate 'x y direction(N,S,E,W)' rover in grid: ";
    char direction;
    cin>>x>>y>>direction;
    while(!grid.isValidCoordinate(x,y)){
        cout<<"ALERT!!!! entre valid coordinate of rover starting point(x y): ";
        cin>>x>>y;
    }
    Rover rover(x, y, direction, grid);

    string commands;
    cout<<"Enter the movement of rover in grid(EXAMPLE 'MMRMLM'): ";
    cin>> commands;
    rover.executeCommands(commands);
    rover.reportStatus();

    return 0;
}
