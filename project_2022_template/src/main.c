#include "project.h"
#include "project.c"


int main(void) {
    while (1) {
        char command[100];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            struct meeting meetings[100];
            int num_meetings = 0;
            scanf("%s", command);
            if (strcmp(command, "structure") == 0) {
                printf("OK\n");
            } else {
                printf("ERROR\n");
            }
        } else if (strcmp(command, "add") == 0) {
            char description[100];
            int month, day, hour;
            scanf("%s %d %d %d", description, &month, &day, &hour);
            add_meeting(description, month, day, hour);
            printf("OK\n");
        } else if (strcmp(command, "delete") == 0) {
            int month, day, hour;
            scanf("%d %d %d", &month, &day, &hour);
            delete_meeting(meetings, &num_meetings, month, day, hour);
            printf("OK\n");
        } else if (strcmp(command, "print") == 0) {
            char description[100];
            int day, month, hour;
            scanf("%s %d.%d at %d", description, &day, &month, &hour);
            print_calendar(meetings, num_meetings, description, day, month, hour);
            printf("OK\n");
        } else if (strcmp(command, "save") == 0) {
            char filename[100];
            scanf("%s", filename);
            save_file(meetings, num_meetings, filename);
            printf("OK\n");
        } else {
            printf("ERROR\n");
        }
    }
}