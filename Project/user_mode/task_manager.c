#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void header()
{
    system("clear");
    puts("");
    puts("--------------------------------< Task Manager >--------------------------------");
    puts("");
}

void task_manager()
{
    int row_count = 1;

    while (1)
    {
        header();
        // system("clear");
        printf("No.    PID\tName\t    CPU Usage   Memory Usage\n");

        FILE *ps_info = popen("ps -eo pid,comm,%cpu,%mem --sort=-%cpu | head -n 10", "r");
        if (ps_info != NULL)
        {
            char line[256];
            while (fgets(line, sizeof(line), ps_info) != NULL)
            {
                int pid;
                char name[50];
                float cpu_usage, mem_usage;
                sscanf(line, "%d %s %f %f", &pid, name, &cpu_usage, &mem_usage);
                printf("%-6d%-9d%-16s%-12.2f%-12.2f\n", row_count++, pid, name, cpu_usage, mem_usage);
            }
            pclose(ps_info);
        }
        else
        {
            printf("Error fetching process information.\n");
        }
        row_count = 1;
        sleep(3);
    }
}

int main()
{
    task_manager();
    return 0;
}
