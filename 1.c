#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_PROCESSES 10

// A process structure to store the process id, burst time and arrival time
struct process
{
    int process_id;
    int burst_time;
    int arrival_time;
};

// Function to compare the burst time of two processes
int compare(const void *a, const void *b)
{
    return ((struct process*)a)->burst_time - ((struct process*)b)->burst_time;
}

int main()
{
    int num_processes, i, total_burst_time = 0;
    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &num_processes);

    printf("Enter the arrival time and burst time of each process:\n");
    for(i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        total_burst_time += processes[i].burst_time;
    }

    qsort(processes, num_processes, sizeof(struct process), compare);

    int current_time = 0, waiting_time = 0;
    for(i = 0; i < num_processes; i++)
    {
        waiting_time += current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
    }

    float average_waiting_time = (float)waiting_time / num_processes;

    printf("\nAverage waiting time: %.2f\n", average_waiting_time);

    return 0;
}
