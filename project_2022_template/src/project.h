#ifndef _PROJECT__H_
#define _PROJECT__H_


struct Meeting {
    char *description;
    int month;
    int day;
    int hour;
};

void addMeeting(struct Meeting *meetings, int *numMeetings, char *description, int month, int day, int hour);
void deleteMeeting(struct Meeting *meetings, int *numMeetings, int month, int day, int hour);
void printMeetings(struct Meeting *meetings, int numMeetings);
void saveToFile(struct Meeting *meetings, int numMeetings, char *filename);
void loadFromFile(struct Meeting *meetings, int *numMeetings, char *filename);
void quitProgram(struct Meeting *meetings, int numMeetings);

#endif //! _PROJECT__H_

