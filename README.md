# shapes_spawn

# Shape Drawing and Animation with Raylib

## Project Overview

This C++ project uses the [Raylib](https://www.raylib.com/) library to read a configuration file containing descriptions of various shapes, such as rectangles and circles, and then draws these shapes on the screen. Each shape is animated and "bounces" off the edges of the window when it reaches them. Additionally, the shape's name is displayed in the center of the shape, using a specified font and color.

The project consists of the following main tasks:
1. **Shape Configuration**: Read from a configuration file (`config.txt`) that specifies the window size, font properties, and shapes (circles and rectangles) with their respective attributes like position, speed, size, and color.
2. **Shape Movement**: Each shape moves across the screen at the specified speed and reverses direction upon colliding with the window edges, creating a "bounce" effect.
3. **Text Display**: The name of each shape is drawn at its center, using the provided font, size, and color.

## Configuration File Format

The `config.txt` file contains different configuration settings, each specified by a unique type identifier. These lines can appear in any order, but the "Window" specification must always come first. Below are the types of settings supported:

1. **Window Configuration**:
   ```plaintext
   Window W H
   ```
   - Defines the window dimensions where `W` is the width and `H` is the height of the window in pixels.
   
2. **Font Configuration**:
   ```plaintext
   Font F S R G B
   ```
   - Specifies the font to be used for the text:
     - `F`: Path to the font file (string)
     - `S`: Font size (integer)
     - `R G B`: RGB color values for the text (integers from 0 to 255)

3. **Rectangle Definition**:
   ```plaintext
   Rectangle N X Y SX SY R G B W H
   ```
   - Defines a rectangle with the following properties:
     - `N`: Name of the rectangle (string)
     - `X Y`: Initial position on the screen (floats)
     - `SX SY`: Initial speed (floats)
     - `R G B`: RGB color values for the rectangle (integers)
     - `W H`: Width and height of the rectangle (floats)

4. **Circle Definition**:
   ```plaintext
   Circle N X Y SX SY R G B R
   ```
   - Defines a circle with the following properties:
     - `N`: Name of the circle (string)
     - `X Y`: Initial position on the screen (floats)
     - `SX SY`: Initial speed (floats)
     - `R G B`: RGB color values for the circle (integers)
     - `R`: Radius of the circle (float)

## Implementation Hints

- **Containers**: Store the shapes in a container, such as `std::vector`, to manage an arbitrary number of shapes.
- **Bounding Box**: You can detect when a shape touches the sides of the window using its bounding box. This can be retrieved using `shape.getLocalBounds()` for the shapes and `text.getLocalBounds()` for the text, which will be useful when positioning and detecting collisions.
- **Collision Detection**: When a shape touches the window edges (left, right, top, or bottom), reverse the corresponding speed component (X or Y).

## Instructions for Building and Running the Project

### Prerequisites

- C++ Compiler (GCC or Clang)
- Raylib (for graphics rendering and handling)

### Building the Project

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/raylib-shapes.git
   cd raylib-shapes
   ```

2. **Compile the program**:
   Assuming that Raylib is installed (instructions below), you can compile the program with:
   ```bash
   g++ -o shape_program main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```

3. **Run the program**:
   ```bash
   ./shape_program
   ```

### How to Install Raylib on Debian Linux

To run this project, you need to install the Raylib library. Here’s how to install Raylib on Debian-based systems (e.g., Ubuntu):

1. **Update your package list**:
   ```bash
   sudo apt update
   ```

2. **Install the necessary dependencies**:
   ```bash
   sudo apt install build-essential libgl1-mesa-dev libopenal-dev
   ```

3. **Download and install Raylib**:
   - Download the latest release from the [Raylib GitHub Releases page](https://github.com/raysan5/raylib/releases).
   - Alternatively, you can install it from the default repositories (may not be the latest version):
     ```bash
     sudo apt install libraylib-dev
     ```

4. **Verify the installation**:
   Compile the included example programs to ensure Raylib is installed correctly:
   ```bash
   gcc -o shapes_example -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```

For further information, you can check the official [Raylib documentation](https://www.raylib.com/) or its GitHub repository.

---


## Acknowledgments

- Thanks to Raylib for making game development in C++ so much easier!
