// Enhanced File Handling - Temperature Logger
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fileptr;           // File pointer for writing data
    int size;                // Number of days to log
    float average = 0.0;     // Average temperature
    float total = 0.0;       // Sum of all temperatures

    printf("=== Temperature Data Logger ===\n");
    printf("How many days of temperature data? ");
    scanf("%d", &size);

    // Input validation
    if (size <= 0 || size > 365) {
        printf("Error: Please enter a valid number of days (1-365)\n");
        return 1;
    }

    // Declare array for temperatures
    float temperatures[100];  // Fixed size array (safer for embedded systems)
    if (size > 100) {
        printf("Error: Maximum 100 days supported\n");
        return 1;
    }

    // Get temperature data from user
    printf("\nEnter temperature data (in Celsius):\n");
    for(int i = 0; i < size; i++) {
        printf("Day %d temperature: ", i + 1);
        scanf("%f", &temperatures[i]);

        // Input validation
        if (temperatures[i] < -50 || temperatures[i] > 60) {
            printf("Warning: Unusual temperature reading!\n");
        }

        total += temperatures[i];    // Add to running total
    }

    // Calculate average
    average = total / size;

    // Open file for writing
    fileptr = fopen("Temperature_Logging.txt", "w");

    if(fileptr == NULL) {
        printf("Error: Cannot create temperature log file!\n");
        return 1;
    }

    // Write header to file
    fprintf(fileptr, "=== Temperature Log Report ===\n");
    fprintf(fileptr, "Total Days Logged: %d\n", size);
    fprintf(fileptr, "================================\n\n");

    // Write temperature data to file
    printf("\n--- Saving data to file ---\n");
    for(int i = 0; i < size; i++) {
        fprintf(fileptr, "Day %2d: %6.1f°C\n", i + 1, temperatures[i]);
        printf(" Day %d data saved\n", i + 1);
    }

    // Write summary statistics
    fprintf(fileptr, "\n--- Summary Statistics ---\n");
    fprintf(fileptr, "Total Temperature: %.1f°C\n", total);
    fprintf(fileptr, "Average Temperature: %.2f°C\n", average);

    // Find min and max temperatures
    float min_temp = temperatures[0];
    float max_temp = temperatures[0];
    int min_day = 1, max_day = 1;

    for(int i = 1; i < size; i++) {
        if(temperatures[i] < min_temp) {
            min_temp = temperatures[i];
            min_day = i + 1;
        }
        if(temperatures[i] > max_temp) {
            max_temp = temperatures[i];
            max_day = i + 1;
        }
    }

    fprintf(fileptr, "Minimum Temperature: %.1f°C (Day %d)\n", min_temp, min_day);
    fprintf(fileptr, "Maximum Temperature: %.1f°C (Day %d)\n", max_temp, max_day);
    fprintf(fileptr, "\n--- End of Report ---\n");

    // Close file
    fclose(fileptr);

    // Display results
    printf("\n=== Results ===\n");
    printf(" Data logged for %d days\n", size);
    printf(" Average temperature: %.2f°C\n", average);
    printf(" Temperature range: %.1f°C to %.1f°C\n", min_temp, max_temp);
    printf(" All data saved to 'Temperature_Logging.txt'\n");

    return 0;
}
