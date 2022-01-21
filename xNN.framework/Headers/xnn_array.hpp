#ifndef _XNN_UTIL_HPP_
#define _XNN_UTIL_HPP_

#define EXPORT __attribute__ ((visibility("default")))
template <typename T>
class  xNNArray {
public:
    // types:
    typedef T                                     value_type;
    typedef T &                                   reference;
    typedef const T &                             const_reference;
    typedef T *                                   pointer;
    typedef const T *                             const_pointer;
    typedef T *                                   iterator;
    typedef const T *                             const_iterator;
    typedef unsigned int                          size_type;
    
    //  construct/copy/destroy:
    xNNArray() noexcept;
    xNNArray(const xNNArray<T> &);
    xNNArray(xNNArray<T> &&) noexcept;
    ~xNNArray();
    xNNArray<T> & operator = (const xNNArray<T> &);
    xNNArray<T> & operator = (xNNArray<T> &&);
    
    // iterators:
    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator cend() const noexcept;
    
    //  capacity:
    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    void resize(size_type);
    void reserve(size_type);
    void shrink_to_fit();
    
    // element access
    reference operator [](size_type);
    const_reference operator [](size_type) const;
    reference at(size_type);
    const_reference at(size_type) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    
    //  data access:
    T * data() noexcept;
    const T * data() const noexcept;
    
    //  modifiers:
    void push_back(const T &);
    void push_back(T &&);
    void pop_back();
    
    void clear() noexcept;
    
private:
    size_type rsrv_sz = 4;
    size_type vec_sz = 0;
    T *arr;
    
    inline void reallocate();
    
};

#define xNN_ARRAY_MAX_SZ 100000

template <typename T>
xNNArray<T>::xNNArray() noexcept {
    arr = new T[rsrv_sz];
}

template <typename T>
xNNArray<T>::xNNArray(const xNNArray<T> &other) {
    size_type i;
    rsrv_sz = other.rsrv_sz;
    arr = new T[rsrv_sz];
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = other.arr[i];
    vec_sz = other.vec_sz;
}

template <typename T>
xNNArray<T>::xNNArray(xNNArray<T> &&other) noexcept {
    size_type i;
    rsrv_sz = other.rsrv_sz;
    arr = new T[rsrv_sz];
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = static_cast<T&&>(other.arr[i]);
    vec_sz = other.vec_sz;
}

template <typename T>
xNNArray<T>::~xNNArray() {
    delete [] arr;
}

template <typename T>
xNNArray<T> & xNNArray<T>::operator = (const xNNArray<T> &other) {
    size_type i;
    if (rsrv_sz < other.vec_sz) {
        rsrv_sz = other.vec_sz << 2;
        reallocate();
    }
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = other.arr[i];
    vec_sz = other.vec_sz;
    return *this;
}

template <typename T>
xNNArray<T> & xNNArray<T>::operator = (xNNArray<T> &&other) {
    size_type i;
    if (rsrv_sz < other.vec_sz) {
        rsrv_sz = other.vec_sz << 2;
        reallocate();
    }
    for (i = 0; i < other.vec_sz; ++i)
        arr[i] = static_cast<T&&>(other.arr[i]);
    vec_sz = other.vec_sz;
    return *this;
}


template <typename T>
typename xNNArray<T>::iterator xNNArray<T>::begin() noexcept {
    return arr;
}

template <typename T>
typename xNNArray<T>::const_iterator xNNArray<T>::cbegin() const noexcept {
    return arr;
}

template <typename T>
typename xNNArray<T>::iterator xNNArray<T>::end() noexcept {
    return arr + vec_sz;
}

template <typename T>
typename xNNArray<T>::const_iterator xNNArray<T>::cend() const noexcept {
    return arr + vec_sz;
}


template <typename T>
inline void xNNArray<T>::reallocate() {
    T *tarr = new T[rsrv_sz];
    //  memcpy(tarr, arr, vec_sz * sizeof(T));
    for (size_type i =0; i<vec_sz; i++) {
        tarr[i] = arr[i];
    }
    delete [] arr;
    arr = tarr;
}


template <typename T>
bool xNNArray<T>::empty() const noexcept {
    return vec_sz == 0;
}

template <typename T>
typename xNNArray<T>::size_type xNNArray<T>::size() const noexcept{
    return vec_sz;
}

template <typename T>
typename xNNArray<T>::size_type xNNArray<T>::max_size() const noexcept {
    return xNN_ARRAY_MAX_SZ;
}

template <typename T>
typename xNNArray<T>::size_type xNNArray<T>::capacity() const noexcept {
    return rsrv_sz;
}

template <typename T>
void xNNArray<T>::resize(typename xNNArray<T>::size_type sz) {
    if (sz > vec_sz) {
        if (sz > rsrv_sz) {
            rsrv_sz = sz;
            reallocate();
        }
    } else {
        size_type i;
        for (i = vec_sz; i < sz; ++i)
            arr[i].~T();
    }
    vec_sz = sz;
}

template <typename T>
void xNNArray<T>::reserve(typename xNNArray<T>::size_type _sz) {
    if (_sz > rsrv_sz) {
        rsrv_sz = _sz;
        reallocate();
    }
}

template <typename T>
void xNNArray<T>::shrink_to_fit() {
    rsrv_sz = vec_sz;
    reallocate();
}


template <typename T>
typename xNNArray<T>::reference xNNArray<T>::operator [](typename xNNArray<T>::size_type idx) {
    return arr[idx];
}

template <typename T>
typename xNNArray<T>::const_reference xNNArray<T>::operator [](typename xNNArray<T>::size_type idx) const {
    return arr[idx];
}

template <typename T>
typename xNNArray<T>::reference xNNArray<T>::at(size_type pos) {
    if (pos < vec_sz)
        return arr[pos];
    
}

template <typename T>
typename xNNArray<T>::const_reference xNNArray<T>::at(size_type pos) const {
    if (pos < vec_sz)
        return arr[pos];
}

template <typename T>
typename xNNArray<T>::reference xNNArray<T>::front() {
    return arr[0];
}

template <typename T>
typename xNNArray<T>::const_reference xNNArray<T>::front() const {
    return arr[0];
}

template <typename T>
typename xNNArray<T>::reference xNNArray<T>::back() {
    return arr[vec_sz - 1];
}

template <typename T>
typename xNNArray<T>::const_reference xNNArray<T>::back() const {
    return arr[vec_sz - 1];
}


template <typename T>
T * xNNArray<T>::data() noexcept {
    return arr;
}

template <typename T>
const T * xNNArray<T>::data() const noexcept {
    return arr;
}

template <typename T>
void xNNArray<T>::push_back(const T &val) {
    if (vec_sz == rsrv_sz) {
        rsrv_sz <<= 2;
        reallocate();
    }
    arr[vec_sz] = val;
    ++vec_sz;
}

template <typename T>
void xNNArray<T>::push_back(T &&val) {
    if (vec_sz == rsrv_sz) {
        rsrv_sz <<= 2;
        reallocate();
    }
    arr[vec_sz] = static_cast<T&&>(val);
    ++vec_sz;
}

template <typename T>
void xNNArray<T>::pop_back() {
    --vec_sz;
    arr[vec_sz].~T();
}

template <typename T>
void xNNArray<T>::clear() noexcept {
    size_type i;
    for (i = 0; i < vec_sz; ++i)
        arr[i].~T();
    vec_sz = 0;
}

template <> inline
void xNNArray<int>::resize(typename xNNArray<int>::size_type sz) {
    if (sz > rsrv_sz) {
        rsrv_sz = sz;
        reallocate();
    }
    vec_sz = sz;
}

template <> inline
void xNNArray<float>::resize(typename xNNArray<float>::size_type sz) {
    if (sz > rsrv_sz) {
        rsrv_sz = sz;
        reallocate();
    }
    vec_sz = sz;
}


template <> inline
void xNNArray<int>::pop_back() {
    --vec_sz;
}

template <> inline
void xNNArray<float>::pop_back() {
    --vec_sz;
}

template <> inline
void xNNArray<int>::clear() noexcept {
    vec_sz = 0;
}

template <> inline
void xNNArray<float>::clear() noexcept {
    vec_sz = 0;
}



class EXPORT xPrediction{
public:
    const char *label;
    float confidence;
    xNNArray<float> position;
    
    xPrediction() noexcept;
    xPrediction(const xPrediction &);
    xPrediction(xPrediction &&) noexcept;
    ~xPrediction(){};
    xPrediction & operator = (const xPrediction &);
    xPrediction & operator = (xPrediction &&);
};
inline
xPrediction::xPrediction() noexcept
{
    confidence = 0.0;
}
inline
xPrediction::xPrediction(const xPrediction &pre)
{
    label = pre.label;
    confidence = pre.confidence;
    for (unsigned int i = 0; i<pre.position.size(); i++) {
        position.push_back(pre.position[i]);
    }
}
inline
xPrediction::xPrediction(xPrediction && pre) noexcept
{
    label = pre.label;
    confidence = pre.confidence;
    for (unsigned int i = 0; i<pre.position.size(); i++) {
        position.push_back(pre.position[i]);
    }
}
inline
xPrediction & xPrediction::operator = (const xPrediction &pre)
{
    label = pre.label;
    confidence = pre.confidence;
    for (unsigned int i = 0; i<pre.position.size(); i++) {
        position.push_back(pre.position[i]);
    }
    return *this;
}

inline
xPrediction & xPrediction::operator = (xPrediction &&pre)
{
    label = pre.label;
    confidence = pre.confidence;
    for (unsigned int i = 0; i<pre.position.size(); i++) {
        position.push_back(pre.position[i]);
    }
    return *this;
}

#endif
