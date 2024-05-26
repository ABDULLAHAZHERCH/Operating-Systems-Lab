#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void header(){
    system("clear");
    puts("");
    puts("--------------------------------< DATE & TIME >--------------------------------");
    puts("");
}

int main() {
    header();
    while (1) {
        // Get current time
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);

        // Extract hours, minutes, seconds, day, month, and year
        int hours = local_time->tm_hour;
        int minutes = local_time->tm_min;
        int seconds = local_time->tm_sec;
        int day = local_time->tm_mday;
        int month = local_time->tm_mon + 1; // Month is 0-indexed
        int year = local_time->tm_year + 1900; // Year is since 1900

        // Print colorful clock
        header();
        printf("                        ╔═════════════════════════════════╗\n");
        printf("                        ║           \033[1;32m%d-%02d-%02d\033[0m            ║\n", year, month, day);
        printf("                        ║           \033[1;31m%02d:%02d:%02d\033[0m              ║\n", hours, minutes, seconds);
        printf("                        ╚═════════════════════════════════╝\n");

        // Wait for one second
        usleep(1000000); // Sleep for 1 second (1000000 microseconds)
    }
    return 0;
}
