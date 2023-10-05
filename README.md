# Mars Rover Command Line Application

This is a C++ command line application for simulating the movement of a Mars rover on a grid with obstacles. The program allows you to define the grid size, place obstacles, and command the rover to move within the grid while avoiding obstacles. This README file provides instructions on how to run the code and an explanation of its structure.

## Getting Started

Follow the steps below to compile and run the Mars Rover simulation code.

### Prerequisites

- A C++ compiler, such as g++, installed on your system.

### Instructions

1. Clone the repository or download the code files to your local machine.

2. Open your terminal or command prompt.

3. Navigate to the directory containing the code files.

4. Compile the code using the following command:

   ```bash
   g++ -o MarsRover MarsRover.cpp
   ```

   This command compiles the code and generates an executable named `MarsRover`.

5. Run the program by executing the following command:

   ```bash
   ./MarsRover
   ```

6. Follow the on-screen instructions to provide the grid size, obstacle coordinates, starting position and direction of the rover, and the movement commands for the rover.

## Code Explanation

The code is organized into classes and follows object-oriented programming principles. Here's an explanation of the key components:

### `Command` (Abstract Class)

- An abstract base class for rover commands (`MoveForwardCommand`, `TurnLeftCommand`, and `TurnRightCommand`).
- Defines a virtual `execute()` method to be implemented by derived classes.

### `GridComponent` (Abstract Class)

- An abstract base class for grid components (`Grid` and `Obstacle`).
- Defines a virtual `hasObstacle()` method to check if there's an obstacle at a specific grid location.

### `Grid`

- Represents the grid on which the rover moves.
- Manages obstacle placement and provides methods to check for obstacles and validate coordinates.

### `MoveForwardCommand`

- A command class that moves the rover forward.
- Checks for obstacles before moving and updates the rover's position.

### `TurnLeftCommand` and `TurnRightCommand`

- Command classes that turn the rover left and right, respectively.
- Update the rover's direction.

### `Rover`

- Represents the Mars rover with its current position and direction.
- Executes a sequence of commands (`M` for move forward, `L` for turn left, `R` for turn right).
- Reports the rover's final position and direction.

### `main()`

- The program entry point.
- Takes user input for grid size, obstacle placement, starting rover position, and movement commands.
- Creates instances of the `Grid` and `Rover` classes.
- Executes the rover's movement commands and reports the final position.

## Running the Program

1. Run the program by executing it in your terminal or command prompt.

2. Enter the grid size (width and height) and the number of obstacles.

3. Input the coordinates of each obstacle.

4. Specify the starting position (x, y) and direction (N, S, E, W) of the rover.

5. Enter the movement commands for the rover (e.g., `MMRMLM`).

6. The program will simulate the rover's movement, and the final position and direction will be displayed.

Enjoy exploring the Mars grid with your rover!
