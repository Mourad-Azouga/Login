#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void stopwatch(void);
void timer(void);
void clockk(void);
int converter(int hours, int minutes, int seconds);

/*
 * Converter - converts hours and minutes into seconds
 * return: total ammount of seconds
*/
int converter(int hours, int minutes, int seconds)
{
    return (hours * 3600 + minutes * 60 + seconds);
}


/*
 * stopwatch - it's a stopwatch 
*/
void stopwatch(void)
{
     int flag = 0, s = 0, m = 0, h = 0;
    int started = 0; // Flag to track if the stopwatch is running

    printf("Stopwatch:\nType 1 to start/pause and 0 to stop\n");
    scanf("%d", &flag);
    if (flag == 1) {
        started = 1;
        while (1) {
            if (started == 1) {
                h = s / 3600;
                m = (s % 3600) / 60;
                printf("\r%.2d:%.2d:%.2d", h, m, s);
                fflush(stdout);
                sleep(1);
                s++;
            }
            scanf("%d", &flag); // Check for user input
            if (flag == 0) {
                started = 0; // Stop the stopwatch
            }
        }
    }
    printf("\nTotal time: %.2d:%.2d:%.2d\n", h, m, s);
}



/*
 *Timer - timer
*/
void timer(void)
{
    int hours = 0 ;int minutes = 0;int seconds = 0; int timer = 0;
    printf("Timer:\nInsert starting time in the following format:\nHours ");
    scanf("%d", &hours);
    printf("Minutes: ");
    scanf("%d", &minutes);
    printf("Seconds: ");
    scanf("%d", &seconds);

        timer = converter(hours, minutes, seconds);
    hours = minutes = seconds = 0;
    while (timer > 0)
    {
        hours = timer / 3600;
        minutes = (timer % 3600) / 60;
        seconds = timer % 60;

        printf("\r%.2d:%.2d:%.2d", hours, minutes, seconds);
        fflush(stdout);

        sleep(1);
        timer--;
    }
printf("%.2d:%.2d:%.2d\n TIMES UP", hours, minutes, seconds);
}
/*
 * Clock - this is a clock
*/
void clockk(void)
{
    int h, m, s;
    printf("Please insert the clock - 24h style only -\n");
    scanf("%d%d%d", &h, &m, &s);
    
    if (h > 24 || m > 60 || s > 60)
    {printf("ERROR"); exit(0);}

    while (1)
    {       printf("\r%.2d:%.2d:%.2d", h, m, s);
            fflush(stdout);
            sleep(1); // Sleep for 1 second
            s++;
            if (s < 60)
            continue;
            else
            {
                m++; s = 0;
            }
            if (m < 60)
            continue;
            else
            {
                h++; m = 0;
            }
            if (h < 24)
            continue;
            else
            {
                h = 0;
            }


    }
}
/* 
 * main - Main program
 * Return: 1 on success and -1 on failure
*/
int main(void)
{

int hour, minute, second, operation;

printf("To use the:\n Stopwatch - type 1.\n Timer - type 2\n Clock - type 3\n To leave - type 0\n");
scanf("%d", &operation);
switch (operation)
{
case 0:
    return (0);
    break;

case 1:
    stopwatch();
  
    break;

case 2:
    timer();
    break;
    
case 3:
    clockk();
    break;
default:
printf("Please select");
    break;
}
} 