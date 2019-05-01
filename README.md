# Overview
Implementation of the std::array container that encapsulates fixed sized arrays

# Implementations
- std::array container
- Methods: 
  - size()
  ```
  template <typename T, size_t N>
  size_t array<T, N>::size() {
    return arr_size;
  }
  ```
  - at()
  ```
  template <typename T, size_t N>
  T& array<T, N>::at(size_t pos) const {
    return ptr[pos];
  }
  ```
  - front()
  ```
  template <typename T, size_t N>
  T& array<T, N>::front() const {
    return ptr[0];
  }
  ```
  - back()
  ```
  template <typename T, size_t N>
  T& array<T, N>::back() const {
    return ptr[arr_size - 1];
  }
  ```
  - to_string()
  ```
  template <typename T, size_t N>
  void array<T, N>::to_string() {
    for(int i = 0; i < arr_size; i++){
        cout << " " << ptr[i] << endl;
    }
  }
  
# Updates (to be)
- New method implementations
- Time complexity on algorithms

# Updated
- N/A
