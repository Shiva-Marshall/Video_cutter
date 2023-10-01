#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Input video file and output cut video file names
    const char *inputFileName = "test.mp4";
    const char *outputFileName = "out.mp4";

    // Start and end timestamps (in seconds) for the desired portion
    double startTime = 10.0;   // Start at 10 seconds
    double endTime = 30.0;     // End at 30 seconds

    // FFmpeg command to cut the video
    char command[256];
    snprintf(command, sizeof(command),
             "ffmpeg -i %s -ss %.2lf -to %.2lf -c copy %s",
             inputFileName, startTime, endTime, outputFileName);

    // Execute the FFmpeg command
    int result = system(command);

    if (result == 0) {
        printf("Video cut successfully.\n");
    } else {
        fprintf(stderr, "Error cutting the video.\n");
    }

    return 0;
}

