# fractol

Project made for 42CommonCore project "fract'ol" @42Firenze by fzucconi.

The aim is to display on screen, using a xlib wrapper library called minlibx, different types of fractals based on the set used to calculate them. The choice (and other optional parameters) are passed via terminal when the program is launched.

## Table of Contents
- [Features](#features)
- [Purpose](#purpose)
- [Logical Steps](#logical-steps)
- [Useful Resources](#useful-resources)

## Features

While in the program is possible to:
- Fractals displayable:
  - Mandelbrot 
  - Julia
  - Burning Ships
  - Tricorn
- Zoom in/out with mouse wheel, with the zoom centered on mouse position.
- Move around and zoom in/out with keyboard.
- Change the iterations of the set, to deepen the drawing.
- Change the base color set.
- Change base parameters with random (for Julia Set).
- Change the zoom "speed".
- And, of course, exit the program =).

## Purpose

The purpose of the project is to become familiar with communication between client and X-Window and to understand how to draw and then display an image.

## Logical Steps

Logical steps involved in writing such a program are:
- Understanding what a fractal is and how it can be displayed.
- (eventually, you will reach to the conclusion that the most simple and probably best way is to take the imaginary part as the y and the real part as the x)
- Opening a communication with X-Window, creating a window, and an image.
- Calculating the chosen set for each point on the screen:
  - Print the pixel in black if the set oscillates between two finite values.
  - Print the pixel in a color varied by the number of repetitions if the set goes to infinity.
- Programming the mouse and keyboard hooks.
- Loop.
- VALGRIND.

## Useful Resources

- Minlibx Documentation Explained (https://harm-smits.github.io/42docs/libs/minilibx)
- Introduction to the minilibX : a simple X-Window programming API in C (by Oceano)
[![Minlibix Explaination](https://img.youtube.com/vi/bYS93r6U0zg/0.jpg)](https://www.youtube.com/watch?v=bYS93r6U0zg)
- How to generate fractals (in french, sub ENG). The first part is enlightening!
[![How to generate fractals (in french, sub ENG)](https://img.youtube.com/vi/wUlVFYJIUNA/0.jpg)](https://www.youtube.com/watch?v=wUlVFYJIUNA)





