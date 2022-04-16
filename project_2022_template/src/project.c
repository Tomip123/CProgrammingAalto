#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GUIDELINES:

// I. You can assume a maximum length for command line entry. For example, 1000 characters is sufficient.
// II. When a command is executed successfully, the program must print SUCCESS\n on the standard output stream.
// III. If the user enters an invalid command, the program must print Invalid command <command>\n on the screen.
// IV. If the command arguments are not valid, the program must print an error message to indicate the error, and must not print SUCCESS\n message. The printed error message must be a single line and must end with a new line character \n.
// V. You must not use user query strings such as Please enter a command: or similar.
// VI. The system assumes that the printed output is US-ASCII encoded. You must not use non-ASCII characters such as Finnish characters.
// VII. In your implementations, you must use dynamic memory to manage the varying memory requirements. Using a large static array or allocating very large array (e.g. malloc(1000000)) to fulfill varying memory requirements is not acceptable.

// GETTING STARTED:

// 1. Start by writing a main function since it is called automatically when execution of your code starts.
// 2. Make an infinite while loop inside your main function. Your application should terminate only when it receives Q command.
// 3. Read a line from user (e.g. using fgets from stdin)
// 4. Resolve command code either using sscanf or get just first character on an input line.
// 5. Use if-else or switch branches for processing each user command.
// 6. Process command parameters using sscanf.
// 7. Have a dedicated function for each command, and name the functions appropriately.

// PROGRAM INSTRUCTIONS:

// Implement a scheduling system that can be used to schedule one-hour meeting times. A meeting is represented with the following data.
// description is the description of the meeting, which is a string that can have arbitrary length. The meeting description may be the same for different meetings.
// month is the month of the meeting time, which is an integer between 1 and 12 (inclusive).
// day is the day of month of the meeting time, which is an integer between 1 and 31 (inclusive).
// hour is hour of the day of the meeting time, which is an integer between 0 and 23 (inclusive).
// For the system, each meeting time must be unique. It should be able to support arbitrary number of meetings.
// The system must be able to process the following commands.

// A. Add meeting command, which adds a new meeting to the system.
// 1. The command has the following format: A <description> <month> <day> <hour>
// For example, a valid add meeting command is as follows: A Haircut 3 26 14
// 2. If the system has another meeting at the specified time, the program must print an error message.

// B. Delete meeting command, which cancels (deletes) a scheduled meeting.
// 1. The command has the following format: D <month> <day> <hour>
// For example, a valid delete meeting command is as follows: D 3 26 14
// 2. If the system does not have a scheduled meeting at the specified time, the program must print an error message.

// C. Print calendar command, which displays the scheduled meetings.
// 1. The command has the following format: L
// 2. It prints the stored meetings on a separate line as follows: <description> <day>.<month> at <hour>
// For example, print calendar command output is as follows:
// Haircut 26.03 at 14
// Exam 02.11 at 08
// SUCCESS
// 3. The time fields must have two digits filled with 0.
// 4. The database entries should be printed in the order of meeting time such that the earlier meetings will be printed first.

// D. Save to file command, which saves the database to a text file.
// 1. The command has the following format: W <filename>
// 2. It writes the stored meetings on a separate line as follows: <description> <day>.<month> at <hour>
// 3. If an error occurs, it must print an error message.

// E. Load from file command, which loads meetings from a text file saved using Save to file command.
// 1. The command has the following format: O <filename>
// 2. It assumes the stored meetings are on a separate line in the format specified above.
// 3. If an error occurs, it should print an error message.
// 4. If the file is valid and loaded correctly, the current game must be replaced with the entries loaded from the file.

// F. Quit program command, which releases all allocated memory and exits the program.
// 1. The command has the following format: Q
// This operation must be implemented so that you can prevent memory leaks.



// Add a new meeting to the system
void addMeeting(struct Meeting *meetings, int *numMeetings, char *description, int month, int day, int hour) {
    
    // Cheking if the month is valid
    if (month < 1 || month > 12) {
        printf("Invalid command: month must be between 1 and 12\n");
        return;
    }

    // Check if the day is valid
    if (day < 1 || day > 31) {
        printf("Invalid command: day must be between 1 and 31\n");
        return;
    }

    // Check if the hour is valid
    if (hour < 0 || hour > 23) {
        printf("Invalid command: hour must be between 0 and 23\n");
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
}

// Delete a meeting from the system
void deleteMeeting(struct Meeting *meetings, int *numMeetings, int month, int day, int hour) {
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
        printf("Invalid command: D %d %d %d\n", month, day, hour);
        printf("Invalid command: no meeting exists at this time\n");
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
            printf("Invalid command: %s\n", command);
        }
    }
    return 0;
}

    
    













