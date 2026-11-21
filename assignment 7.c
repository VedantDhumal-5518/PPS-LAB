#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store robot details
struct Robot {
    int id;
    char type[30];
    float capacity;
    float load;
    float operating_time;
    float load_utilization;
    char status[15];
};

int main() {
    int n;

    // Step 2: Read number of robots
    printf("Enter the number of robots: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of robots.\n");
        return 1;
    }

    // Allocate memory for n robots
    struct Robot *robots = (struct Robot *)malloc(n * sizeof(struct Robot));
    if (robots == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Loop for each robot i = 0 to n-1
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details for Robot %d ---\n", i + 1);
        
        printf("Robot ID: ");
        scanf("%d", &robots[i].id);
        
        printf("Robot Type: ");
        scanf("%s", robots[i].type);
        
        printf("Capacity (kg): ");
        scanf("%f", &robots[i].capacity);
        
        printf("Current Load (kg): ");
        scanf("%f", &robots[i].load);
        
        printf("Operating Time (hrs): ");
        scanf("%f", &robots[i].operating_time);

        // Calculate load utilization = (load / capacity) * 100
        if (robots[i].capacity > 0) {
            robots[i].load_utilization = (robots[i].load / robots[i].capacity) * 100.0;
        } else {
            robots[i].load_utilization = 0.0;
        }

        // Check for overload condition
        if (robots[i].load > robots[i].capacity) {
            strcpy(robots[i].status, "Overload");
        } else {
            strcpy(robots[i].status, "Within limit");
        }
    }

    // Step 4: Display the details of all robots in tabular form
    printf("\n========================================================================================\n");
    printf("%-10s %-15s %-15s %-12s %-15s %-15s %-15s\n", 
           "Robot ID", "Type", "Capacity(kg)", "Load(kg)", "Op Time(hrs)", "Utilization(%)", "Status");
    printf("========================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-15.2f %-12.2f %-15.2f %-15.2f %-15s\n",
               robots[i].id,
               robots[i].type,
               robots[i].capacity,
               robots[i].load,
               robots[i].operating_time,
               robots[i].load_utilization,
               robots[i].status);
    }
    printf("========================================================================================\n");

    // Free dynamically allocated memory
    free(robots);

    // Step 5: Stop
    return 0;
}
