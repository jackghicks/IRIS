#include <stdio.h>
#include <thread> 
#include <chrono>
#include "../include/iris/IrisHelper.h"

typedef void (*irisProgressCallback)(const char *error, const char *progress);

void analyseVideo(const char *videoPath, irisProgressCallback callback)
{
    if (videoPath == nullptr || callback == nullptr)
    {
        callback("Invalid arguments", nullptr);
        return;
    }

    // Simulate video processing
    for (int i = 0; i <= 100; i += 10)
    {
        char progress[50];
        snprintf(progress, sizeof(progress), "Processing: %d%%", i);
        callback(nullptr, progress);
        // Simulate some processing delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    // Simulate completion
    callback(nullptr, "Processing complete");
}