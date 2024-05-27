extern "C" {
    typedef void (*irisProgressCallback)(const char* error, const char* progress);
    void analyseVideo(const char *videoPath, irisProgressCallback callback);
}