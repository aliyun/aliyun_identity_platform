//
//  xnn_image_process.hpp
//  xNN
//
//  Created by taoyuan on 2018/7/24.
//  Copyright © 2018年 Reis. All rights reserved.
//

#ifndef XNN_IMAGE_PROCESS_HPP
#define XNN_IMAGE_PROCESS_HPP

#define EXPORT __attribute__ ((visibility("default")))
//---------------class xNNImage------------------//
typedef enum
{
    RESIZE_METHOD_NEAREST = 0,
    RESIZE_METHOD_BILINEAR = 1,
}IMAGE_RESIZE_METHOD;

class EXPORT xNNImage
{
public:
    xNNImage(void);
    ~xNNImage();
    
    bool SetImageSize(int width, int height);
    bool SetImageFormat(int format);
    bool SetImageData(unsigned char *data);
    //set data pointer, the second parameter used for UV data
    bool SetImageData(unsigned char *dataY, unsigned char *dataUV);
    
    int  GetImageWidth();
    int  GetImageHeight();
    int  GetImageFormat();
    
    inline unsigned char* GetImageData() {return imageData[0];}
    inline unsigned char* GetImageData(int i) {return imageData[i];}
    //----------xNNImagePreprocess----------
    //IMAGE PREPROCESS, RETURN THE RESULT
    //Process Order:rotate->crop->convert->resize
    //PARAMETERS:
    //--srcImage     : input image, imageData should allocate before use these functions.
    //--dstImage     : output image, imageData should allocate before use these functions.
    //--rotation     : contrarotate, support 0,90,180,270
    //--roi          : the area in the image, roi[0~1] : coordinates of the upper left corner; roi[2~3] : width and height of the area
    //--valuePad     : if roi area out of the image, use valuePad to pad
    //--newWidth     : output image width
    //--newHeight    : output image height
    //--newFormat    : output image format: 0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
    //--resizeMethod : 0 : nearest; 1 : bilinear
    //RETURN:
    //--bool value   : true : success; false : failed;
    static bool xNNImageProcess(xNNImage srcImage, xNNImage *dstImage, int rotation, int *roi, unsigned char valuePad,
                                int newWidth, int newHeight, int newFormat, IMAGE_RESIZE_METHOD resizeMethod);
    
    // the order of execution
    // Crop -> Resize -> Convert -> Rotate
    // Resize : now only support bilinear
    // each step is independent with neon optimized
    static bool xNNImageProcess_Optimized(xNNImage srcImage, xNNImage *dstImage,
                                          int rotation, int *roi, unsigned char valuePad,
                                          int newWidth, int newHeight, int newFormat, IMAGE_RESIZE_METHOD resizeMethod);
    //for rotation
    static bool xNNImageRotate(xNNImage srcImage, xNNImage *dstImage,
                               int rotation, int newWidth, int newHeight, int newFormat);
    //for crop
    static bool xNNImageCrop(xNNImage srcImage, xNNImage *dstImage,
                             int *roi, int valuePad, int newWidth, int newHeight, int newFormat);
    //for convert
    static bool xNNImageConvert(xNNImage srcImage, xNNImage *dstImage,
                                int newWidth, int newHeight, int newFormat);
    //for resize
    static bool xNNImageResize(xNNImage srcImage, xNNImage *dstImage,
                               int newWidth, int newHeight, int newFormat, IMAGE_RESIZE_METHOD resizeMethod);
private:
    unsigned char *imageData[2];
    int imageFormat;
    int imageWidth;
    int imageHeight;
};

#endif /* XNN_IMAGEPROCESS_HPP */
