#pragma once

#include <string>
#include <vector>
#include <map>

#ifndef EXPORT
#  define EXPORT __attribute__ ((visibility("default")))
#endif

struct Result {
    bool kv_pair;
    std::string label;
    std::string key;
    float conf;
    std::vector<float> pos;

    Result() {
        kv_pair = false;
        label = "";
        key = "";
        conf = 0.0f;
        std::vector<float>().swap(pos);
    }
};

using Results = std::vector<Result>;

const int PIX_FMT_UNKNOWN = -1;
const int PIX_FMT_NV12 = 0;
const int PIX_FMT_RGB = 1;
const int PIX_FMT_RGBA = 2;
const int PIX_FMT_BGRA = 3;
const int PIX_FMT_BGR = 4;
const int PIX_FMT_NV21 = 5;
const int PIX_FMT_GRAY = 6;

struct Image {
    unsigned char* data;
    unsigned char* extra_data;
    int width;
    int height;
    int format; // 0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray

    Image() {
        data = nullptr;
        extra_data = nullptr;
        width = 0;
        height = 0;
        format = PIX_FMT_UNKNOWN;
    }
};

//struct for blox
struct ResultInfo{
    virtual ~ResultInfo() = default;
    Results results;
    int imageDegree;
    int imageMirror;
    Image fullImage;
    Image roiImage;
    Image resultImage;
};

