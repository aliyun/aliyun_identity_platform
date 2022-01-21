#ifndef _XNN_HPP_
#define _XNN_HPP_

#include "xnn_errno.h"
#include "xnn_array.hpp"
#define XNN_VERSION "10.1.92"

typedef enum {
  kxNNNoType = 0,
  kxNNFloat32 = 1,
  kxNNInt32 = 2,
  kxNNUInt8 = 3,
  kxNNInt64 = 4,
  kxNNString = 5,
  kxNNBool = 6,
  kxNNInt16 = 7,
  kxNNInt8 = 8,
  kxNNFloat16 = 9,
} xNNType;

// CallBack function defination
struct xTensor{
  const char * name;
  xNNArray<int> shape;
  xNNType type;
  const void* buffer;
  long long buffer_size;
};

// CallBack function defination
typedef bool (*xCallBack)(const xNNArray<xTensor*>&);

class EXPORT xNNSharedModel{
public:
  virtual ~xNNSharedModel (){};
};

class EXPORT xNN {
public:
  
  xNN (const char *model_file,const char *configString = nullptr);
  
  xNN (unsigned char *model_filebuffer,int bufferlenth,const char *configString = nullptr);
  
  xNN (xNNSharedModel* model,const char *configString = nullptr);
  
  virtual ~xNN ();
  
  virtual bool          RegisterCallBack        (const char* location, xCallBack* func);
  
  // Return the type of a tensor by name.
  virtual xNNType       GetInputType            (const char * tensor_name = "");
  virtual xNNType       GetOutputType           (const char * tensor_name = "");

  // Do forward process from input blob/tensor to output blob/tensor
  virtual bool          Forward                 ();
  virtual xNNArray<xTensor> Forward             (xNNArray<xTensor>& input_tensors);
  
  // Return the shape of a tensor by name.
  virtual xNNArray<int> GetInputShape           (const char* blob_name = "") ;
  virtual xNNArray<int> GetOutputShape          (const char* blob_name = "") ;
  
  // Set the shape of the input blob/tensor
  virtual bool          SetShape                (xNNArray<int> &,  const char* blob_name = "") ;
  
  // Propagate the shape of input blob/tensor throughout the model to reallocate memories
  virtual bool          PropagateShape          (void);
  
  // Return the pointer of the input blob/tensor by name
  virtual float*        GetInput                (const char* blob_name = "") ;
  virtual const float*  GetOutput               (const char* blob_name = "") ;
  
  virtual const char*   GetVersion              () noexcept { return XNN_VERSION;}
  
  virtual XNN_ERROR     GetStatus               () noexcept;
  virtual void          ClearStatus             () noexcept; 
  
  // Return the number of input blobs/tensors
  virtual int           GetNumInputs            () ;
  virtual int           GetNumOutputs           () ;
  virtual const char*   GetInputName            (int index) ;
  virtual const char*   GetOutputName           (int index) ;
  virtual xNNArray<xPrediction> GetFormattedOutputs     () ;
  
  // Return the type of model initialed in xNN
  virtual bool          SetNumCPUThreads        (int num_threads) noexcept;
  
  // Training interface
  virtual bool          ExportUpdates           (const char* export_path);
private:
  XNN_ERROR                                     status_{ENONE};
  void*                                         xnn_ {nullptr};
};


extern "C" xNN* xNN_init_from_file(const char *model_file, const char *configString);
extern "C" xNN* xNN_init_from_buffer(unsigned char *model_filebuffer,int bufferlenth,const char *configString);
extern "C" xNN* xNN_init_from_shared_model(xNNSharedModel* sharedModel,const char* configString);
extern "C" void xNN_release(xNN *xnn);

extern "C" xNNSharedModel* xNN_model_init_from_file(const char *model_file, const char *configString);
extern "C" xNNSharedModel* xNN_model_init_from_buffer(unsigned char *model_filebuffer,int bufferlenth,const char *configString);
extern "C" void xNN_model_release(xNNSharedModel *xnn);

extern "C" bool xNN_shared_model_apply_patch_file(xNNSharedModel *xnn, const char *patch_file);

#endif
