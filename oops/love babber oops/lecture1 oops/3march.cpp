#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int priority;
    int burst_time;
} Process;

typedef struct {
    Process processes[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue queues[3]; // Three separate queues for MLQ
int quantum[3] = {4, 2, 1}; // Quantum for each queue
int time_slice[3] = {16, 8, 4}; // Time slice for each queue
int current_time = 0;
int num_processes = 0;
Process processes[MAX_PROCESSES];
int completed[MAX_PROCESSES] = {0};

void enqueue(Queue *queue, Process process) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        exit(1);
    }
    queue->rear++;
    queue->processes[queue->rear] = process;
}

Process dequeue(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    Process process = queue->processes[queue->front];
    queue->front++;
    return process;
}

void add_process(int pid, int priority, int burst_time) {
    Process process = {pid, priority, burst_time};
    enqueue(&queues[priority], process);
    num_processes++;
}

void schedule_process(Process process, int current_queue) {
    int time_left = process.burst_time;
    int i;
    for (i = 0; i < time_slice[current_queue]; i++) {
        if (time_left > 0) {
            printf("Processing process %d at time %d\n", process.pid, current_time);
            time_left--;
            current_time++;
        } else {
            break;
        }
    }
    if (time_left > 0) {
        // Process didn't complete, move it to the next queue
        int next_queue = current_queue + 1;
        if (next_queue < 3) {
            enqueue(&queues[next_queue], process);
        } else {
            // Lowest priority queue, keep running it until completion
            while (time_left > 0) {
                printf("Processing process %d at time %d\n", process.pid, current_time);
                time_left--;
                current_time++;
            }
            completed[process.pid] = 1;
        }
    } else {
        // Process completed, mark it as done
        completed[process.pid] = 1;
    }
}

void run_processes() {
    int i, j;
    for (i = 0; i < 3; i++) {
        while (queues[i].front <= queues[i].rear) {
            Process process = dequeue(&queues[i]);
            for (j = 0; j < quantum[i]; j++) {
                if (process.burst_time > 0) {
                    schedule_process(process, i);
                } else {
                    break;
                }
            }
            if (process.burst_time > 0) {
                // Process didn't complete, move it to the back of the queue
            }
        }}}
