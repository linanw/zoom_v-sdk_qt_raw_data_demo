#include "opencvtextrecognition.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;
using namespace cv::dnn;


OpenCVTextRecognition::OpenCVTextRecognition()
{

}

unsigned char* OpenCVTextRecognition::DetectText(unsigned char* input_yuv, unsigned char* output_yuv, int width, int height){
    Mat yuv = Mat(height / 2 * 3, width, CV_8UC1, reinterpret_cast<unsigned char *>(input_yuv)); // YUV bitmap is 1.5 times taller then the orignal image.
    Mat gray = Mat(height, width, CV_8UC1, input_yuv); // grayscale bitmap is for face detection

    Mat bgr;
    cvtColor(yuv, bgr, COLOR_YUV2BGR_I420);



//    float binThresh = parser.get<float>("binaryThreshold");
//    float polyThresh = parser.get<float>("polygonThreshold");
//    uint maxCandidates = parser.get<uint>("maxCandidate");
//    String detModelPath = parser.get<String>("detModelPath");
//    String recModelPath = parser.get<String>("recModelPath");
//    String vocPath = parser.get<String>("vocabularyPath");
//    double unclipRatio = parser.get<double>("unclipRatio");
////    int height = parser.get<int>("inputHeight");
////    int width = parser.get<int>("inputWidth");
////    int imreadRGB = parser.get<int>("RGBInput");

//    // Load networks
//        CV_Assert(!detModelPath.empty());
//        TextDetectionModel_DB detector(detModelPath);
//        detector.setBinaryThreshold(binThresh)
//                .setPolygonThreshold(polyThresh)
//                .setUnclipRatio(unclipRatio)
//                .setMaxCandidates(maxCandidates);

//        CV_Assert(!recModelPath.empty());
//        TextRecognitionModel recognizer(recModelPath);
}
