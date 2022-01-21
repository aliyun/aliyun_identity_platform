//
//  xnn_image_atom.hpp
//  xNN
//
//  Created by yuanlongjie on 2020/7/2.
//  Copyright © 2020 Reis. All rights reserved.
//

#ifndef xnn_image_atom_h
#define xnn_image_atom_h

#include "xnn_image_process.hpp"

//----------xNNImageRotate_Atom----------
//for rotation
//PARAMETERS:
//--srcImage     : input image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--dstImage     : output image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--rotation     : contrarotate, support 0,90,180,270
//RETURN:
//--bool value   : true : success; false : failed;
extern "C" bool xNNImageRotate_Atom(xNNImage srcImage, xNNImage *dstImage, int rotation);

//----------xNNImageCrop_Atom----------
//for crop
//PARAMETERS:
//--srcImage     : input image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--dstImage     : output image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--roi          : the area in the image, roi[0~1] : coordinates of the upper left corner;
//                                        roi[2~3] : width and height of the area
//--padValue     : if roi area out of the image, use padValue to pad
//RETURN:
//--bool value   : true : success; false : failed;
extern "C" bool xNNImageCrop_Atom(xNNImage srcImage, xNNImage *dstImage, int *roi, int padValue);

//----------xNNImageConvert_Atom----------
//for vonvert
//PARAMETERS:
//--srcImage     : input image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--dstImage     : output image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//do convert from srcImage format to dstImage format
//RETURN:
//--bool value   : true : success; false : failed;
extern "C" bool xNNImageConvert_Atom(xNNImage srcImage, xNNImage *dstImage);

typedef enum
{
  NON_PROPORTIONAL_SCALING = 0,
  PROPORTIONAL_SCALING = 1,
} SCALE_MODE;
//----------xNNImageResizeBilinear_Atom----------
//for resize bilinear
//PARAMETERS:
//--srcImage     : input image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--dstImage     : output image, imageData should allocate before use these functions.
//                 need set imageData/Size/Format
//--mode         : NON_PROPORTIONAL_SCALING ---- w_scale & h_scale is computed by itself
//                   PROPORTIONAL_SCALING   ---- w & h use the same scale which is computed by min(w_scale, h_scale),
//                                               If the target dimensions don't match the image dimensions, the image
//                                               is resized and then padded with zeroes to match requested dimensions.
//--padValue     : use padValue to pad if needed
//do resize bilinear from srcImage size to dstImage size
//RETURN:
//--bool value   : true : success; false : failed;
extern "C" bool xNNImageResizeBilinear_Atom(xNNImage srcImage, xNNImage *dstImage, SCALE_MODE mode = NON_PROPORTIONAL_SCALING, unsigned char padValue = 0);

#endif /* xnn_image_atom_h */
