# DriveStraightML
I made a robot teach itself how to drive in a straight line. The code is in RobotC, specifically running on a Vex Cortex 2.0.

Here is the general idea.
Initialize the left and right motors with seperate random motor controller (MC) values

While (true) {
  Drive for 5 seconds
  wait for the user to enter the calculated distance (distance along y axis / angle off of zero)
  if the new calculated distance is better than the old distance, pick new MC values near those last MC values
  otherwise pick new MC values around the last best MC values
