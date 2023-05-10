#include <stdio.h>
#include <stdlib.h>

// function to select the maximum profit by scheduling the jobs
void job_sequencing(int deadline[], int profit[], int n) {
    // sort the jobs based on their profits
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[j] > profit[i]) {
                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;
            }
        }
    }

    // array to store the time slots for each job
    int timeslots[n];

    // initialize all time slots as available
    for (int i = 0; i < n; i++) {
        timeslots[i] = -1;
    }

    // select the jobs
    int profit_total = 0;
    for (int i = 0; i < n; i++) {
        // find the latest available time slot before the job's deadline
        int j;
        for (j = deadline[i] - 1; j >= 0; j--) {
            if (timeslots[j] == -1) {
                timeslots[j] = i + 1;
                profit_total += profit[i];
                break;
            }
        }
    }

    // print the selected jobs and the total profit
    printf("Selected jobs: ");
    for (int i = 0; i < n; i++) {
        if (timeslots[i] != -1) {
            printf("%d ", timeslots[i]);
        }
    }
    printf("\nTotal profit: %d\n", profit_total);
}

// main function
int main() {
    // input the number of jobs
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // input the deadline and profit of each job
    int deadline[n], profit[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the deadline and profit of job %d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
    }

    // select the maximum profit by scheduling the jobs
    job_sequencing(deadline, profit, n);

    return 0;
}