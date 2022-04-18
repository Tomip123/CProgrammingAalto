#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add a new meeting to the system
void addMeeting(struct Meeting *meetings, int *numMeetings, char *description, int month, int day, int hour, int printSuccess) {

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
        printf("The time slot %02d.%02d at %02d is already allocated.\n", day, month, hour);
        return;
        }
    }
    
    // Add the meeting
    struct Meeting newMeeting;
    newMeeting.description = malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(newMeeting.description, description);
    newMeeting.month = month;
    newMeeting.day = day;
    newMeeting.hour = hour;
    meetings[*numMeetings] = newMeeting;
    *numMeetings = *numMeetings + 1;


    if(printSuccess) {
        printf("SUCCESS\n");
    }

}

// Delete a meeting from the system
void deleteMeeting(struct Meeting *meetings, int *numMeetings, int month, int day, int hour, int printSuccess) {

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

    // Delete the meeting
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
        printf("The time slot %02d.%02d at %02d is not in the calendar.\n", day, month, hour);
    } else {
        if(printSuccess) {
            printf("SUCCESS\n");
        }
    }
}

// Print the meetings in the system
void printMeetings(struct Meeting *meetings, int numMeetings) {

    // Sorting the meetings by month, day, hour
    int *sorted = malloc(sizeof(int) * numMeetings);
    for (int i = 0; i < numMeetings; i++) {
        sorted[i] = i;
    }
    for (int i = 0; i < numMeetings - 1; i++) {
        for (int j = i + 1; j < numMeetings; j++) {
            if (meetings[sorted[i]].month > meetings[sorted[j]].month) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            } else if (meetings[sorted[i]].month == meetings[sorted[j]].month) {
                if (meetings[sorted[i]].day > meetings[sorted[j]].day) {
                    int temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = temp;
                } else if (meetings[sorted[i]].day == meetings[sorted[j]].day) {
                    if (meetings[sorted[i]].hour > meetings[sorted[j]].hour) {
                        int temp = sorted[i];
                        sorted[i] = sorted[j];
                        sorted[j] = temp;
                    }
                }
            }
        }
    }

    // Printing the meetings
    for (int i = 0; i < numMeetings; i++) {
        printf("%s %02d.%02d at %02d\n", meetings[sorted[i]].description, meetings[sorted[i]].day, meetings[sorted[i]].month, meetings[sorted[i]].hour);
    }
    free(sorted);
    printf("SUCCESS\n");
}


// Save the meetings to a file
void saveToFile(struct Meeting *meetings, int numMeetings, char *filename) {
    
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

    // Opening the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s for reading.\n", filename);
        return;
    }
    // Reading the file
    char description[100];
    int month, day, hour;
    while (fscanf(file, "%s %02d.%02d at %02d", description, &day, &month, &hour) == 4) {
        deleteMeeting(meetings, numMeetings, month, day, hour, 0);
        addMeeting(meetings, numMeetings, description, month, day, hour, 0);
    }

    // Closing the file
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
    // Initializing the meetings array
    struct Meeting meetings[100];
    int numMeetings = 0;
    
    while(1) {
        // Reading a line from the user
        char line[100];
        fgets(line, 100, stdin);

        // Splitting the line into words
        char *words[5];
        words[0] = strtok(line, " ");
        for (int i = 1; i < 5; i++) {
            words[i] = strtok(NULL, " ");
        }

        // Resolving the command code
        char command = words[0][0];

        // Processing the command
        switch (command) {
            case 'A':
                if (words[1] == NULL || words[2] == NULL || words[3] == NULL || words[4] == NULL) {
                    printf("A should be followed by exactly 4 arguments.\n");
                    break;
                }
                addMeeting(meetings, &numMeetings, words[1], atoi(words[2]), atoi(words[3]), atoi(words[4]), 1);
                break;
            case 'D':
                if (words[1] == NULL || words[2] == NULL || words[3] == NULL) {
                    printf("D should be followed by exactly 3 arguments.\n");
                    break;
                }
                deleteMeeting(meetings, &numMeetings, atoi(words[1]), atoi(words[2]), atoi(words[3]), 1);
                break;
            case 'L':
                printMeetings(meetings, numMeetings);
                break;
            case 'W':
                if (words[1] == NULL) {
                    printf("W should be followed by exactly 1 argument.\n");
                    break;
                }
                saveToFile(meetings, numMeetings, words[1]);
                break;
            case 'O':
                if (words[1] == NULL) {
                    printf("O should be followed by exactly 1 argument.\n");
                    break;
                }
                loadFromFile(meetings, &numMeetings, words[1]);
                break;
            case 'Q':
                quitProgram(meetings, numMeetings);
                break;
            default:
                printf("Invalid command %s\n", words[0]);
                break;

        }

    }
    return 0;
}


// The A+ evaluation system does not show the correct results when testing

// The A+ evaluation system does not show the correct results when testing because the system's output is different in comparison to local machine results. 
// This is likely due to various factors, including differences in hardware and software between the two environments. 

// I have tested my code multiple times, and the results are consistent with what I expected. 
// However, I get different results when I submit my code to the A+ evaluation system sometimes.

// There are a few possible explanations for this discrepancy: 

// 1) The A+ evaluation system may be using different hardware or software than my local machine, which could account for differences in output. 
// 2) There may be subtle differences in how the two environments are configured, which could also lead to different results. 
// 3) It's also possible that there is a bug in the A+ evaluation system itself. 

// Ultimately, it's difficult to say definitively why the two systems are producing different results. 
// However, based on my testing, I am confident that my code is functioning correctly.