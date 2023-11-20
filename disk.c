#include<stdio.h>
#include<stdlib.h>

// Function to perform SSTF disk scheduling
void sstf(int n, int head, int req[]) {
    int i, j, temp, total_seek = 0;
    int visited[n];

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("SSTF Disk Scheduling:\n");

    for (i = 0; i < n; i++) {
        int min_seek = 1e9, min_index;

        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int seek = abs(head - req[j]);
                if (seek < min_seek) {
                    min_seek = seek;
                    min_index = j;
                }
            }
        }

        visited[min_index] = 1;
        total_seek += min_seek;
        head = req[min_index];

        printf("Move to %d\n", head);
    }

    printf("Total seek time: %d\n", total_seek);
}

int main() {
    int n, head, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int req[n];

    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &req[i]);
    }

    sstf(n, head, req);
    printf("\n");

    return 0;
}
