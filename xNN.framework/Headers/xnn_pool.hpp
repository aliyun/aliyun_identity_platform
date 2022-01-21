//
//  xnn_instance_pool.hpp
//  xNN
//
//  Created by taoyuan on 2019/6/18.
//  Copyright © 2019 Reis. All rights reserved.
//

#ifndef xnn_instance_pool_hpp
#define xnn_instance_pool_hpp

#include <stdio.h>
#include "xnn.hpp"
#include "xnn_errno.h"

class EXPORT xNNPool
{
public:
    xNNPool(){};
    // clear and destroy
    virtual ~xNNPool();
    

    virtual int loadModel(const char *model_file,char *config,int boundaryMin,int boundaryMax);
    
    virtual int loadModel(unsigned char *model_buffer, int length,char *config,int boundaryMin,int boundaryMax);
    
    virtual void setBoundaryMin(int instanceMin);
    virtual void setBoundaryMax(int boundaryMax);
    virtual int  getBoundaryMin();
    virtual int  getBoundaryMax();
    
    virtual void clear();
    
    virtual void *getInstance();
    virtual void freeInstance(void* actuator);

private:
    void destroy();
    void *xnn_shared_model_ { nullptr};
    void *xnn_instance_pool_ { nullptr};
    char *config_string_{nullptr};
    int boundary_min_ {0};
    int boundary_max_ {0};
    int cur_ins_count_{0};
};

extern "C" xNNPool* xNN_pool_new();
extern "C" void xNN_pool_release(xNNPool *xnn);


#endif /* xnn_instance_pool_hpp */
