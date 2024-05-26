#include <stdio.h>
#include <stdlib.h>

void web_browser(const char *url)
{
    char command[100];
    snprintf(command, sizeof(command), "xdg-open %s", url);
    system(command);
}

int main()
{
    char url[100];
    printf("Enter the URL you want to open: ");
    if (fgets(url, sizeof(url), stdin) == NULL)
    {
        fprintf(stderr, "Error reading URL.\n");
        return 1;
    }

    // Remove newline character from input
    url[strcspn(url, "\n")] = '\0';

    web_browser(url);

    return 0;
}
