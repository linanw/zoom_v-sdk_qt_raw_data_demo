#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>

#include "OpenCVObjectDetect.h"

using namespace std;
using namespace cv;

OpenCVObjectDetect::OpenCVObjectDetect()
{
    cascade_ = new CascadeClassifier("banana_classifier.xml");
}

void OpenCVObjectDetect::TagObject(unsigned char* frame_in, unsigned char* frame_out, int width, int height)
{
    // YUV matrix is 1.5 times tall of a frame.
    Mat yuv = Mat(height / 2 * 3, width, CV_8UC1, frame_in);
    Mat gray = Mat(height, width, CV_8UC1, frame_in);

    // ...
    Mat bgr;
    cvtColor(yuv, bgr, COLOR_YUV2BGR_I420);
    vector<Rect> results;
    vector<double> weights;
    vector<int> levels;

    // detect objects
    cascade_->detectMultiScale(gray, results, 1.2, 3, 0, Size(250,125), Size(310,155));

    // tag objects
    for(int n = 0; n < (int)results.size(); n++){
        auto result = results[n];
        rectangle(bgr, Rect(result.x+40, result.y -40, result.width-60, result.height), Scalar(0, 255, 0), 2);

        putText(bgr,
            format("banana"),
            Point(result.x +40, result.y - 5 -40), // top-left position
            FONT_HERSHEY_SIMPLEX,
            1.0,
            CV_RGB(0, 255, 0), // font color
            1
        );
    }

    Mat yuv_r;
    cvtColor(bgr, yuv_r, COLOR_BGR2YUV_I420);

    if(!isSampleSaved){
        imwrite("yuv.tiff", yuv);
        imwrite("yuv_r.tiff", yuv_r);
        imwrite("gray.tiff", gray);
        imwrite("bgr.tiff", bgr);
        isSampleSaved = true;
    }
    unsigned char* p;
    for (int i = 0; i < height / 2 * 3; ++i) {
        p = yuv_r.ptr<uchar>(i);
        for (int j = 0; j < width; ++j) {
            frame_out[i * width + j] = p[j];
        }
    }
    return;
}
