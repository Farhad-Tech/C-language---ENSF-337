/*
*  lab1exe_D.c
*  ENSF - Fall 2018 Lab 1, exercise D
*  Completed by: Farhad Alishov
*  Lab Section: B02
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;

    printf("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);

    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }

    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }

  create_table(velocity);

    return 0;
}

double Projectile_travel_time(double a, double v){
  double time = 2*v*sin(a)/G;
  return time;
}

double Projectile_travel_distance(double a, double v){
  double dis = v*v*sin(2*a)/G;
  if (dis < 0){
    dis = 0;
  }
  return dis;
}

double degree_to_radian(double d){
  double rad = d/180*PI;
  return rad;
}

void create_table(double v){
  printf("\n");
  printf("Your velocity is %lf", v);
  printf("\n");
  printf("Angle\t\tt\t\td\n");
  printf("(deg)\t\t(sec)\t\t(m)\n");
  int ang;
  for (ang=0; ang<=90; ang+=5){
    printf("%d\t\t%lf\t%lf\n", ang, Projectile_travel_time(degree_to_radian(ang), v), Projectile_travel_distance(degree_to_radian(ang), v));
  }

}

/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */
