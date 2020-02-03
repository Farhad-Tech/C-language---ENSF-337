/*
 * Farhad Alishov
 * lab2exe_D1.c
 * ENSF 337 - Lab 2 - Execise D Part I
 *  This program lets you examine the behaviour of simple scanf calls
 *  in response to input errors.
 */

#include <stdio.h>

void get_user_input(double* distance, double* speed);
void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
void display_info( double distance, double speed, double hour, double minutes);

int main(void)
{
  double dis1;
  double spe2;
  double hou3;
  double min4;
  get_user_input(&dis1, &spe2);
  travel_time_hours_and_minutes(dis1, spe2, &hou3, &min4);
  display_info(dis1, spe2, hou3, min4);
  return 0;
}

void get_user_input(double* distance, double* speed){
  int nscan;

  printf("Please enter the travel distance in km: \n");
  nscan = scanf("%lf", distance);

  printf("Now enter the vehicle's average speed (km/hr): \n");
  nscan = scanf("%lf", speed);
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes){
  *hours = (int)(distance/speed);
  *minutes = ((distance/speed-*hours)*60);
}

void display_info(double distance, double speed, double hour, double minutes){
  printf("You have travel %lf (km) with a speed of %lf in %lf hour(s) and %lf minute(s)\n", distance, speed, hour, minutes);
}
