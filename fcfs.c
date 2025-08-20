/*“Write a C program to implement First Come First Serve (FCFS)
 CPU scheduling algorithm to calculate Waiting Time, 
 Turnaround Time, and their averages.”*/

#include <stdio.h>

#define MAX 30

int main() {
    int i, j, n, bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time = %f", awt);
    printf("\nAverage Turnaround Time = %f\n", atat);

    return 0;
}