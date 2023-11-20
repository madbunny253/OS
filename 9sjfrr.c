#include <stdio.h>
#include <stdbool.h>

struct Process 
{
    int id;           // Process ID
    int arrival_time; // Arrival time
    int burst_time;   // Burst time
    int remaining_time; // Remaining burst time for preemption
};

void SJF(struct Process processes[], int n) 
{
    int current_time = 0;
    int completed = 0;
    bool visited[n];

    for (int i = 0; i < n; i++) 
	{
        visited[i] = false;
    }

    printf("Order of execution for SJF (Preemptive):\n");

    while (completed < n) {
        int shortest_job_index = -1;
        int shortest_job_burst = 999999;

        for (int i = 0; i < n; i++) 
		{
            if (!visited[i] && processes[i].arrival_time <= current_time &&
                processes[i].burst_time < shortest_job_burst) {
                shortest_job_index = i;
                shortest_job_burst = processes[i].burst_time;
            }
        }

        if (shortest_job_index != -1) 
		{
            printf("P%d ", processes[shortest_job_index].id);
            visited[shortest_job_index] = true;
            completed++;
            current_time += processes[shortest_job_index].burst_time;
        } 
		else 
		{
            current_time++;
        }
    }
    printf("\n");
}

void RR(struct Process processes[], int n, int time_quantum) 
{
    int current_time = 0;
    int completed = 0;

    printf("Order of execution for Round Robin:\n");

    while (completed < n) 
	{
        for (int i = 0; i < n; i++) 
		{
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) 
			{
                int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                processes[i].remaining_time -= execute_time;
                current_time += execute_time;
                printf("P%d ", processes[i].id);

                if (processes[i].remaining_time == 0) 
				{
                    completed++;
                }
            }
        }
    }

    printf("\n");
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) 
	{
        processes[i].id = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    printf("Order of execution for SJF (Preemptive):\n");
    SJF(processes, n);
    
    printf("Order of execution for Round Robin:\n");
    RR(processes, n, time_quantum);

    return 0;
}
