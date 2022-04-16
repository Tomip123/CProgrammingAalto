#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add a new meeting to the system
void addMeeting(struct Meeting *meetings, int *numMeetings, char *description, int month, int day, int hour) {
    
    // Cheking if the month is valid
    if (month < 1 || month > 12) {
        printf("Month cannot be less than 1 or greater than 12.\n");
        return;
    }

    // Check if the day is valid
    if (day < 1 || day > 31) {
        printf("Day cannot be less than 1 or greater than 31.\n");
        return;
    }

    // Check if the hour is valid
    if (hour < 0 || hour > 23) {
        printf("Hour cannot be negative or greater than 23.\n");
        return;
    }

    // Check if the meeting already exists
    for (int i = 0; i < *numMeetings; i++) {
        if (meetings[i].month == month && meetings[i].day == day && meetings[i].hour == hour) {
            printf("Invalid command: A %s %d %d %d\n", description, month, day, hour);
            printf("Invalid command: meeting already exists at this time\n");
            return;
        }
    }

    // Allocating memory for the new meeting
    meetings[*numMeetings].description = malloc(sizeof(char) * strlen(description));

    // Copying the description
    strcpy(meetings[*numMeetings].description, description);

    // Copying the month
    meetings[*numMeetings].month = month;

    // Copying the day
    meetings[*numMeetings].day = day;

    // Copying the hour
    meetings[*numMeetings].hour = hour;

    // Incrementing the number of meetings
    (*numMeetings)++;  

    printf("SUCCESS\n");
}

// Delete a meeting from the system
void deleteMeeting(struct Meeting *meetings, int *numMeetings, int month, int day, int hour) {

    // Check if the month is valid
    if (month < 1 || month > 12) {
        printf("Month cannot be less than 1 or greater than 12.\n");
        return;
    }

    // Check if the day is valid
    if (day < 1 || day > 31) {
        printf("Day cannot be less than 1 or greater than 31.\n");
        return;
    }

    // Check if the hour is valid
    if (hour < 0 || hour > 23) {
        printf("Hour cannot be negative or greater than 23.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *numMeetings; i++) {
        if (meetings[i].month == month && meetings[i].day == day && meetings[i].hour == hour) {
            free(meetings[i].description);
            for (int j = i; j < *numMeetings - 1; j++) {
                meetings[j] = meetings[j + 1];
            }
            (*numMeetings)--;
            found = 1;
        }
    }
    if (!found) {
        printf("The time slot %d %d at %d is not in the calendar.\n", month, day, hour);
    }
    printf("SUCCESS\n");
}

// Print the meetings in the system
void printMeetings(struct Meeting *meetings, int numMeetings) {
    // 1. It prints the stored meetings on a separate line as follows: <description> <day>.<month> at <hour>
    // 2. The time fields must have two digits filled with 0.
    // 3. The database entries should be printed in the order of meeting time such that the earlier meetings will be printed first.

    // Sorting the meetings by time
    for (int i = 0; i < numMeetings - 1; i++) {
        for (int j = i + 1; j < numMeetings; j++) {
            if (meetings[i].hour > meetings[j].hour) {
                struct Meeting temp = meetings[i];
                meetings[i] = meetings[j];
                meetings[j] = temp;
            }
            else if (meetings[i].hour == meetings[j].hour) {
                if (meetings[i].day > meetings[j].day) {
                    struct Meeting temp = meetings[i];
                    meetings[i] = meetings[j];
                    meetings[j] = temp;
                }
                else if (meetings[i].day == meetings[j].day) {
                    if (meetings[i].month > meetings[j].month) {
                        struct Meeting temp = meetings[i];
                        meetings[i] = meetings[j];
                        meetings[j] = temp;
                    }
                }
            }
        }
    }

    // The number have always two digits. For example if the number is 1, it will be printed as 01
    char *hour = malloc(sizeof(char) * 3);
    char *day = malloc(sizeof(char) * 3);
    char *month = malloc(sizeof(char) * 3);

    // Printing the meetings
    for (int i = 0; i < numMeetings; i++) {
        sprintf(hour, "%02d", meetings[i].hour);
        sprintf(day, "%02d", meetings[i].day);
        sprintf(month, "%02d", meetings[i].month);
        printf("%s %s.%s at %s\n", meetings[i].description, day, month, hour);
    }

    free(hour);
    free(day);
    free(month);

    printf("SUCCESS\n");

}

// Save the meetings to a file
void saveToFile(struct Meeting *meetings, int numMeetings, char *filename) {
    // 1. The command has the following format: W <filename> where <filename> is the name of the text file to which the meetings are saved.
    // 2. It writes the stored meetings on a separate line as follows: <description> <day>.<month> at <hour>
    // 3. If an error occurs, it must print an error message.

    // Opening the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Invalid command: W %s\n", filename);
        printf("Invalid command: file could not be opened\n");
        return;
    }

    // Writing the meetings to the file
    for (int i = 0; i < numMeetings; i++) {
        fprintf(file, "%s %d.%d at %d\n", meetings[i].description, meetings[i].day, meetings[i].month, meetings[i].hour);
    }

    // Closing the file
    fclose(file);

    printf("SUCCESS\n");

    
}

// Save the meeting to a file
void loadFromFile(struct Meeting *meetings, int *numMeetings, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Invalid command: O %s\n", filename);
        return;
    }
    char description[100];
    int month, day, hour;
    while (fscanf(file, "%s %d.%d at %d", description, &day, &month, &hour) == 4) {
        addMeeting(meetings, numMeetings, description, month, day, hour);
    }
    fclose(file);
    printf("SUCCESS\n");
}

// Quit the program
void quitProgram(struct Meeting *meetings, int numMeetings) {
    for (int i = 0; i < numMeetings; i++) {
        free(meetings[i].description);
    }
    printf("SUCCESS\n");
    exit(0);
}

// Main function
int main () {
    struct Meeting meetings[100];
    int numMeetings = 0;
    char command[100];
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "A") == 0) {
            char description[100];
            int month, day, hour;
            scanf("%s %d %d %d", description, &month, &day, &hour);
            addMeeting(meetings, &numMeetings, description, month, day, hour);
        } else if (strcmp(command, "D") == 0) {
            int month, day, hour;
            scanf("%d %d %d", &month, &day, &hour);
            deleteMeeting(meetings, &numMeetings, month, day, hour);
        } else if (strcmp(command, "L") == 0) {
            printMeetings(meetings, numMeetings);
        } else if (strcmp(command, "W") == 0) {
            char filename[100];
            scanf("%s", filename);
            saveToFile(meetings, numMeetings, filename);
        } else if (strcmp(command, "O") == 0) {
            char filename[100];
            scanf("%s", filename);
            loadFromFile(meetings, &numMeetings, filename);
        } else if (strcmp(command, "Q") == 0) {
            quitProgram(meetings, numMeetings);
        } else {
            printf("Invalid command %s\n", command);
        }
    }
    return 0;
}

    
    













