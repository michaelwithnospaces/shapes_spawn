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

To add instructions on how to build the project using the provided `CMakeLists.txt` and Makefile, follow these steps to include it in the `README.md`:

---

## Building the Project with CMake

This project uses CMake to manage the build process. Below are the steps to build the project from the provided `CMakeLists.txt`.

### Prerequisites

Make sure you have the following installed on your system:
- **CMake**: Version 3.2 or higher
- **Raylib**: Installed and available on your system (See [Raylib Installation](#how-to-install-raylib-on-debian-linux) instructions if needed)
- **C++ Compiler**: GCC or Clang that supports C++11 or higher.

### Build Instructions

1. **Navigate to your project directory**:
   Open a terminal and move to the root directory of the project, where the `CMakeLists.txt` file is located:

   ```bash
   cd /path/to/your/project
   ```

2. **Create a build directory**:
   It’s a good practice to keep build files in a separate directory. Create a `build/` directory:

   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake**:
   In the `build` directory, run `cmake` to generate the necessary makefiles for your project:

   ```bash
   cmake ..
   ```

   This command will:
   - Set the project to use C++11 as specified in `CMakeLists.txt`.
   - Locate all the `.cpp` files in the `src/` directory.
   - Link your project with the Raylib library.

4. **Build the project**:
   Once the CMake configuration is complete, run the `make` command to compile and build the project:

   ```bash
   make
   ```

   This will generate an executable file named `ASSIGNMENT_1` in the `build/` directory.

5. **Run the project**:
   After the build is complete, run the generated executable:

   ```bash
   ./ASSIGNMENT_1
   ```

   The application should now launch and display the shapes as per the configuration in `config.txt`.

### Cleaning the Build Files

If you want to clean the build files and start fresh, you can use:

```bash
make clean
```

This will remove the previously built files but keep the CMake configuration. You can delete the `build/` directory manually if you want to fully reset.

---

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
