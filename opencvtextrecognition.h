#ifndef OPENCVTEXTRECOGNITION_H
#define OPENCVTEXTRECOGNITION_H


class OpenCVTextRecognition
{
public:
    OpenCVTextRecognition();
    unsigned char* DetectText(unsigned char* input_yuv, unsigned char* output_yuv, int width, int height);
};

#endif // OPENCVTEXTRECOGNITION_H
