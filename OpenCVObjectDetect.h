#ifndef OPENCVOBJECTDETECT_H
#define OPENCVOBJECTDETECT_H

#include <opencv2/objdetect.hpp>

using namespace cv;

class OpenCVObjectDetect
{
public:
    OpenCVObjectDetect();
    void TagObject(unsigned char* input_yuv, unsigned char* output_yuv, int width, int height);
    bool isSampleSaved = false;
private:
    CascadeClassifier *cascade_;
};

#endif // OPENCVOBJECTDETECT_H
