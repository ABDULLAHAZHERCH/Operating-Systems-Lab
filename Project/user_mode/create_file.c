#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <string.h>

struct FileInfo
{
    char filename[100];
    char content[1000];
    off_t size;
    time_t creation_time;
    uid_t owner_uid;
    char owner_name[100];
};

void header()
{
    system("clear");
    puts("");
    puts("--------------------------------< Create File >--------------------------------");
    puts("");
}

void create_file(struct FileInfo *file_info)
{
    FILE *file;

    file = fopen(file_info->filename, "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s", file_info->content);

    fclose(file);

    struct stat file_stat;
    if (stat(file_info->filename, &file_stat) != -1)
    {
        file_info->size = file_stat.st_size;
        file_info->creation_time = file_stat.st_ctime;
        file_info->owner_uid = file_stat.st_uid;

        struct passwd *pw = getpwuid(file_stat.st_uid);
        if (pw != NULL)
        {
            strcpy(file_info->owner_name, pw->pw_name);
        }
        else
        {
            strcpy(file_info->owner_name, "Unknown");
        }

        printf("File created and information stored successfully.\n");
    }
    else
    {
        printf("Error getting file information.\n");
    }
}

void print_file_info(const struct FileInfo *file_info)
{
    char c;
    printf("\nFile information : \n");
    puts("----------------");
    printf("Filename: %s\n", file_info->filename);
    printf("Size: %ld bytes\n", (long)file_info->size);
    printf("Creation time: %s", ctime(&file_info->creation_time));
    printf("Owner: %s (UID: %d)\n", file_info->owner_name, file_info->owner_uid);
    puts("Press any key to continue!");
    scanf(" %c", c);
}

int main()
{
    header();
    struct FileInfo file_info;

    printf("Enter filename: ");
    scanf("%s", file_info.filename);

    printf("Enter content to write to the file:\n");
    scanf(" %[^\n]s", file_info.content);

    create_file(&file_info);

    print_file_info(&file_info);

    return 0;
}
