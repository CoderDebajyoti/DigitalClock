#include <stdio.h>
#include <time.h>
#include <unistd.h>

void displayClock(int hours, int minutes, int seconds) {
    printf("\r%02d:%02d:%02d", hours, minutes, seconds);
    fflush(stdout);
}

int main() {
    time_t rawtime;
    struct tm *timeinfo;

    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        int hours = timeinfo->tm_hour;
        int minutes = timeinfo->tm_min;
        int seconds = timeinfo->tm_sec;

        displayClock(hours, minutes, seconds);
        sleep(1); // wait for 1 second
    }

    return 0;
}

