# self-driving-car-PID-Controller
- [Udacity PID Controller Project](https://github.com/udacity/CarND-PID-Control-Project): this project is to apply a PID controller to the simulator. The simulator provides cross-track error (CTE), speed, and steering value. The PID controller has to respond with steering value in order to drive the car on the track.

[//]: # (Image References)
[pid_algorithm]: ./assets/algorithm.PNG

## CTE (Cross Track Error) algorithm

![alt text][pid_algorithm]

- **Proportional control**: steer the car based on the proportion of the distance from the center of road. This distance from the center of road is alse called CTE. For example, if P=0.1 and the car is off to the left, this will steer 10% of the CTE to the right direction ( opposite direction). If we take a bigger proportion, it will cause strong overshooting problem.
- **Differential control**: this part solves the problem of overshooting the center line from P control part. The proper D value should stablize the car from wabbling. 
- **Integral control**: this part compensates the systematic bias in the CTE which prevents the PD controller from reaching the center line.


## Manually tunning parameters process
### Only P
- P parameter= 0.1: pretty good in the beginning, start wabbling when it comes to the curve.
- P parameter= 0.5: start wabbling soon after the start. Obviously, it is overshooting from the center line.
- P parameter= 0.3: wabbling soon after the start. This is overshooting.

**result**: 0.1 is best P value. But in order to find the best D parameter to solve overshooting, we will use P=0.3. 
### P+D
- (P,D) = (0.3,0.1): overshooting problem gets worse.
- (P,D) = (0.3,0.01): overshooting problem is still terrible.
- (P,D) = (0.3,0.0001): overshooting get better.
- (P,D) = (0.3,0.00001): overshooting get even better.

**result**: 0.00001 is best D value. Let's use best P and best D to test.
- (P,D) = (0.1,0.00001): works good in the beginning. It start wabbling a lot from the curve and run off the road after little while.

### P+D+I 
- (P,D,I) = (0.1, 0.00001, 0.1): Goes off the road at the curve.
- (P,D,I) = (0.1, 0.00001, 0.9): Goes off the road at the curve.
- (P,D,I) = (0.1, 0.00001, 1.5): It worked. This values can finish one lap. The car gets very close to the edge of road at the curve sometimes. So I decided to keep increasing I value.
- (P,D,I) = (0.1, 0.00001, 3.0): better. Let's keep increasing the I value to 5.0.
- (P,D,I) = (0.1, 0.00001, 5.0): little better result.

**Conclusion**: D-value solves overshooting; I-value solves off the track problem at the curve. The best parameters are (P,D,I) = (0.1, 0.00001, 5.0).

## Tiwddle
