# 3D Rocket Launch Simulation

## Introduction

### Aim
The main theme of the project is to display the rocket launch from one end to another end or to dispatch it to launch a satellite using basic computer graphics. This graphics package is based on the OpenGL library functions. The programming language used here is C using OpenGL libraries. The content of the rocket is dispatched to convert into a satellite in the GLUT library. We have used keyboard keys to interact with the program. The graphics used here are simple, easy to understand, and attractive. This model engages users during the simulation, building interest and enthusiasm till the end of the model execution. Users may also learn about the launching activity, its movement, and gain overall knowledge of handling the rocket simulation.

### Overview
The "Rocket Launch" project is a computer graphics simulation using OpenGL functions. It is an interactive program that allows users to view and control the rocket launch display using input devices like the keyboard and mouse. The project focuses on visualizing the process of a rocket launch, providing a dynamic and engaging experience for the user. It leverages the low-level rendering capabilities of OpenGL and utilizes the GLUT library for additional functionality. The rocket launch simulation is divided into three major steps:

1. **Initial Representation:**
    - The program generates a 3D representation of the rocket, Earth, and stars.
    - The rocket is initially static, placed on the launchpad or a starting position.
    - The Earth is rendered as a spherical object, possibly rotating to simulate the planet’s motion.

2. **Launch and Animation:**
    - The user triggers the launch sequence using keyboard or mouse interactions.
    - The countdown begins, building anticipation for the launch.
    - Once the countdown finishes, the rocket is launched.
    - The rocket starts moving upwards into the sky, with realistic motion and trajectory.
    - Animation effects may include exhaust flames, smoke, or other visual elements to enhance realism.

3. **Final Rendering:**
    - The rocket continues its ascent, eventually reaching space.
    - The scene transitions to the space environment, displaying the rocket against a backdrop of stars or celestial objects.
    - Additional animations or effects can be incorporated, such as satellite deployment or stage separation.
    - The user can observe the rocket's movement and monitor its progress.

### Outcome
The "Rocket Launch" program provides a visually appealing and interactive simulation of a rocket launch. It allows users to experience the process of a rocket leaving Earth's atmosphere and entering space. The program incorporates realistic rendering, animation, and user control to create an engaging and educational experience. Users can observe the launch sequence, monitor the rocket's movement, and gain a better understanding of the complexities involved in a real-life rocket launch.

### OpenGL API’s with Description
1. `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`: Clears the color and depth buffers.
2. `glLoadIdentity()`: Replaces the current matrix with the identity matrix.
3. `gluLookAt()`: Defines a viewing transformation, specifying the position and orientation of the camera.
4. `glPushMatrix()`: Pushes the current matrix stack down by one, duplicating the current matrix.
5. `glTranslatef()`: Translates the current matrix by a specified amount in the x, y, and z-directions.
6. `glRotatef()`: Applies a rotation transformation to the current matrix.
7. `glScalef()`: Scales the current matrix by a specified amount in the x, y, and z directions.
8. `glVertex3f()`: Specifies a vertex in 3D space.
9. `glBegin(GL_QUAD_STRIP)`: Indicates the start of a sequence of vertices for drawing a quadrilateral strip.
10. `glEnd()`: Indicates the end of a sequence of vertices.
11. `glColor3f()`: Sets the current color for subsequent drawing operations.
12. `glMaterialfv()`: Sets material properties for lighting calculations.
13. `glLightfv()`: Sets light source properties.
14. `glEnable()`: Enables various capabilities, such as lighting or depth testing.
15. `glDisable()`: Disables various capabilities.
16. `glutSwapBuffers()`: Swaps the buffers of the current window, displaying the rendered image.

