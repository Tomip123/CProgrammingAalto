#ifndef _PROJECT__H_
#define _PROJECT__H_

// Struct to hold meeting data
struct Meeting {
    char *description;
    int month;
    int day;
    int hour;
};

// Add a meeting to the array of meetings
void addMeeting(struct Meeting *meetings, int *numMeetings, char *description, int month, int day, int hour, int printSuccess);

// Delete a meeting from the array of meetings
void deleteMeeting(struct Meeting *meetings, int *numMeetings, int month, int day, int hour, int printSuccess);

// Print all meetings
void printMeetings(struct Meeting *meetings, int numMeetings);

// Save meetings to file
void saveToFile(struct Meeting *meetings, int numMeetings, char *filename);

// Load meetings from file
void loadFromFile(struct Meeting *meetings, int *numMeetings, char *filename);

// Free the memory allocated to the meetings and exit the program
void quitProgram(struct Meeting *meetings, int numMeetings);

#endif //! _PROJECT__H_

