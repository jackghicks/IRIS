#include <stdio.h>
#include "iris/IrisHelper.h"
#include "iris/Configuration.h"
#include "iris/VideoAnalyserV2.h"

typedef void (*irisProgressCallback)(const char *error, const char *progress);

void analyseVideo(const char *videoPath, irisProgressCallback callback)
{
    if (videoPath == nullptr || callback == nullptr)
    {
        callback("Invalid arguments", nullptr);
        return;
    }

    iris::Configuration configuration;
    configuration.Init();

    iris::VideoAnalyserV2 videoAnalyser(&configuration, &callback);
    videoAnalyser.AnalyseVideo(false, videoPath);

    // Simulate completion
    callback(nullptr, "complete");
}