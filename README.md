# self-driving-car-PID-Controller

[//]: # (Image References)
[pid_algorithm]: ./assets/algorithm.PNG

## CTE (Cross Track Error) algorithm

![alt text][pid_algorithm]

- **Proportional control**: steer the car based on the proportion of the distance from the center of road. This distance from the center of road is alse called CTE. For example, if P=0.1 and the car is off to the left, this will steer 10% of the CTE to the right direction ( opposite direction). If we take a bigger proportion, it will cause strong overshooting problem.
- **Differential control**: this part solves the problem of overshooting the center line from P control part. The proper D value should stablize the car from wabbling. 
- **Integral control**: this part compensates the systematic bias in the CTE which prevents the PD controller from reaching the center line.


## Manual tunning parameter
### Only P
Wabble

overshoot


### P+D


### P+D+I 

## Tiwddle
