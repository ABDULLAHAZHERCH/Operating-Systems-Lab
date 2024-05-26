#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
 
#define MAX_FILENAME_LEN 256
#define MAX_CONTENT_LEN 1024

void save_to_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
        fputs(content, file);
        fclose(file);
        printf("File saved successfully.\n");
    }
    else
    {
        printf("Error: Could not save file.\n");
    }
}

void notepad()
{
    char filename[MAX_FILENAME_LEN];
    char content[MAX_CONTENT_LEN];

    printf("Enter the file name : ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    printf("Enter your text :\n");

    initscr();  // Initialize ncurses
    noecho();   // Do not echo user input
    timeout(0); // Set non-blocking mode

    int ch;
    int pos = 0;

    while (1)
    {
        ch = getch(); // Get a character (non-blocking)

        if (ch != ERR)
        { // If a character was pressed
            if (ch == 27)
            { // Check for escape key (ASCII code 27)
                save_to_file(filename, content);
                printf("File saved. Exiting notepad.\n");
                break;
            }
            else if (pos < MAX_CONTENT_LEN - 1)
            { // Limit content size
                content[pos++] = ch;
                content[pos] = '\0';
                addch(ch); // Display the character on the screen
                refresh(); // Refresh the screen
            }
        }
    }

    endwin(); // End ncurses
}

int main()
{
    notepad();
    // After notepad exits, you can display the menu or perform other actions
    return 0;
}
