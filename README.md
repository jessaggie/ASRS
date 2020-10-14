# ASRS
CODE Guide:

Code is commented and straightforward. 


5 files included: Full, getCurrent, kill, forwards, and backwards.
Encoder pack also included

Note, you will need to install additional Arduino packages for the current sensor and encoder (the encoder pack is included). 

The Arduino pack INA219 can be sourced by going to sketch and clicking ‘Include a library’ and searing ‘INA219’. When found, install.

The encoder pack is included in this folder and should be installed by going to sketch and clicking ‘include a library’, and then, ‘add a .zip library’ . Please then navigate to either the zipped folder or the unzipped folder and select one to install it.  


Programs:

	Full:

Full is the full program for automation. This program reads from the current sensor and encoder and writes to the motor driver. The programs starts the motor running to move the rack forward. The current sensor and encoders are read from. The encoder reading is divided by the number of ticks on the encoder and multiplied by the circumference of the pinion gear to get linear distance from 1 rotation, which is distance traveled (1 dimensional odometry). The maximum depth is recorded as the highest number the distance traveled variable gets to. When the pipe makes contact with a solid object, the motor will have more difficulty moving which will cause the current to spike in the motor. This spike is used as the the signal for when the pipe hits an object. When this is the case the motor reverses causing the pipe to retract until the distance traveled is back at 0. The process then repeats. 


	getCurrent:

This is a sample program that is used to read the current from the current sensor.  Run this program to get the current. Set the baud rate to 115200.

	kill:

Kill is program designed to stop the motor output. "all is good, all is quiet" is printed every 2 seconds. This program should be run if an immediate stop is needed.

	Forwards:

To offer a foreword on this program, the script starts the motors and drives them forward continuously. The main purpose of this program is to move the rack in and out of place. There is also a section in this program to print the encoder results to see distance traveled in mm. 


	Backwards:

This program drives the motors backwards continuously. The main purpose of this program is to move the rack in and out of place. 


//Motor Driver

In 1
In 2
out 1
out 2
action
0
0
High Z
High Z
coasting
0
1
Low 
High
Backwards
1
0
High 
Low
Forwards
1
1
Low 
Low
Brake



  //methods of movement
  //you can use both analog write or digital write. 
  //analog write is a pwm signal and is driven with the command:
  // analogWrite(MOTOR_IN(insert motor number here), (range from 0 to 255));  
  //255 is 100% while 0 is 0%
  //digital write can also be used with the command:
  //digitalWrite(MOTOR_IN(insert motor number here), (1 or 0 or HIGH or LOW));



Guide for the current sensor:
https://learn.adafruit.com/adafruit-ina219-current-sensor-breakout

Guide for the motor driver:
https://learn.adafruit.com/adafruit-drv8871-brushed-dc-motor-driver-breakout


Email: jessaggie@tamu.edu or jorbaustin@gmail.com with any issues. 

