
# Virtual Painter


## Overview

The **Virtual Painter** project is an interactive application that uses OpenCV to track colored objects in real-time via webcam and allows the user to paint on the screen by moving the objects. This project detects specific colors (e.g., green) and draws corresponding points on the screen, creating a virtual painting experience.

## Features

- **Real-Time Color Detection**: Tracks specific colors in real-time using a webcam.
- **Drawing on Screen**: Allows the user to paint by moving a colored object in front of the camera.
- **Horizontal Flip**: Flips the webcam feed horizontally to create a more natural drawing experience (i.e., avoiding the mirror effect).

## Prerequisites

Before running the project, make sure you have the following installed:

- **OpenCV**: Installed and configured in your C++ development environment.
- **C++ Compiler**: For building and running the project.

## Setup

1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd Virtual-Painter
   ```

2. **Install OpenCV**:
   - Ensure OpenCV is properly installed and configured in your development environment.

3. **Build the Project**:
   - Compile the code using your preferred C++ compiler, making sure to link the OpenCV libraries.

## Usage

1. **Run the Project**:
   - Execute the compiled program to start the virtual painting process.
   - Hold an object of the specified color (e.g., green) in front of the webcam and move it around to draw on the screen.

2. **View Results**:
   - The live webcam feed will be displayed with the drawn points as you move the colored object.

## Code Explanation

The main parts of the project code include:

- **Color Detection**:
  ```cpp
  vector<vector<int>> myColors{
      {35, 50, 50, 85, 255, 255}    // Green
  };
  ```
  - The `myColors` vector contains HSV color ranges for detecting the desired color (green in this case).

- **Finding and Drawing Points**:
  ```cpp
  vector<vector<int>> findColor(Mat img) {
      // Detects the specified color and stores the coordinates
  }

  void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
      // Draws circles at the detected points
  }
  ```

- **Flipping the Image**:
  ```cpp
  flip(img, img, 1); // Flip the image horizontally to avoid mirror effect
  ```
  - The `flip` function is used to flip the webcam feed horizontally, providing a more intuitive drawing experience.

## Customization

- **Adding New Colors**: You can add more colors by extending the `myColors` vector and assigning corresponding colors in `myColorValues`.
- **Adjusting Color Ranges**: Tweak the HSV ranges in `myColors` to detect different shades or colors.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit a pull request with your improvements or fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- **OpenCV**: For providing the tools and libraries that made this project possible.


![Screenshot 2024-08-11 193946](https://github.com/user-attachments/assets/c3505c6f-c1d9-4b28-a83b-98694f5659ce)
---
