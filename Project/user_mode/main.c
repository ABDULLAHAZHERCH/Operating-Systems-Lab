#include <stdio.h>
#include <unistd.h>
#include <string.h>

void header()
{
    system("clear");
    // create a header
    puts("");
    puts("--------------------------------< My Operating System >--------------------------------");
    puts("");
}

void startup(int ram, int hard_drive_size, int num_cores)
{
    printf("Operating System is starting with the following specifications:\n");
    printf("RAM: %d GB\n", ram);
    printf("Hard Drive Size: %d GB\n", hard_drive_size);
    printf("Number of CPU Cores: %d\n", num_cores);
    printf("\nLoading:\n");

    for (int i = 3; i >= 1; i--)
    {
        printf("\r%2d", i);
        fflush(stdout);
        sleep(1);
    }

    system("clear");
}

int menu()
{
    int input;
    puts("1.  Clock ");
    puts("2.  Notepad ");
    puts("3.  Create File and Check Info ");
    puts("4.  Move File ");
    puts("5.  Delete File ");
    puts("6.  Calculator ");
    puts("7.  System Monitor ");
    puts("8.  Task Manager ");
    puts("9.  Web Browser ");
    puts("10. Word Guess Game ");
    printf("\nSelect your option : ");
    scanf("%d", &input);
    return input;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <RAM> <Hard Drive Size> <Number of Cores>\n", argv[0]);
        return 1;
    }
    int ram = atoi(argv[1]);
    int hard_drive_size = atoi(argv[2]);
    int num_cores = atoi(argv[3]);

    startup(ram, hard_drive_size, num_cores);
    while (1)
    {
        header();
        int input = menu();
        if (input == 1)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "clock", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 2)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "notepad", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 3)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "create_file", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 4)
        {
            // move file
        }
        else if (input == 5)
        {
            // delete file
        }
        else if (input == 6)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "calculator", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 7)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "system_monitor", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 8)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "task_manager", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 9)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "web_browser", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
        else if (input == 10)
        {
            int pid = fork();

            if (pid == 0)
            {
                char *args[] = {"./new_terminal", "game", NULL};
                execvp(args[0], args);
                perror("execvp");
                return 1;
            }
            else if (pid < 0)
            {
                perror("fork");
                return 1;
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}
