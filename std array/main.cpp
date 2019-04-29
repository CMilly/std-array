#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

template <typename T, size_t N>
class array{
private:
    T* ptr;
    size_t arr_size;
public:
    array();
    ~array(); // destructor
    array(const initializer_list<T> &list);
    size_t size();
    T &operator[](size_t pos) const;
    T& at(size_t pos) const;
    T& front() const;
    T& back() const;
    void to_string();
};

/**
 * Constructor - initializer list
 * @tparam T
 * @tparam N
 * @param list
 */
template <typename T, size_t N>
array<T, N>::array(const initializer_list<T> &list) {
    arr_size = list.size();
    ptr = new T[arr_size];

    for(int i = 0; i < arr_size; i++){
        ptr[i] = list.begin()[i]; //https://stackoverflow.com/questions/17787394/why-doesnt-stdinitializer-list-provide-a-subscript-operator
    }
}

/**
 * Default constructor
 * @tparam T
 * @tparam N
 */
template <typename T, size_t N>
array<T, N>::array(){
    arr_size = N;
    ptr = new T[arr_size];
}

/**
 * Destructor
 * @tparam T
 * @tparam N
 */
template <typename T, size_t N>
array<T, N>::~array() {
    delete []ptr;
}

/**
 * Return a reference to the element at index
 * @tparam T
 * @tparam N
 * @param index
 * @return T element @ ptr[index]
 */
//Operator subscript[] overloading
template <typename T, size_t N>
T& array<T, N>::operator[](size_t index) const {
    return ptr[index];
}

/**
 * Return a reference to the element at pos
 * @tparam T
 * @tparam N
 * @param pos
 * @return T element @ ptr[pos]
 */
template <typename T, size_t N>
T& array<T, N>::at(size_t pos) const {
    return ptr[pos];
}

/**
 * Return a reference to the front element
 * @tparam T
 * @tparam N
 * @return T element @ ptr[0]
 */
template <typename T, size_t N>
T& array<T, N>::front() const {
    return ptr[0];
}

/**
 * Return a reference to the back element
 * @tparam T
 * @tparam N
 * @return T element @ ptr[arr_size - 1]
 */
template <typename T, size_t N>
T& array<T, N>::back() const {
    return ptr[arr_size - 1];
}

/**
 * Return the size of array
 * @tparam T
 * @tparam N
 * @return size_t
 */
template <typename T, size_t N>
size_t array<T, N>::size() {
    return arr_size;
}

/**
 * String the contents of array
 * @tparam T
 * @tparam N
 */
template <typename T, size_t N>
void array<T, N>::to_string() {
    for(int i = 0; i < arr_size; i++){
        cout << " " << ptr[i] << endl;
    }
}

int main() {
    array<int, 4> my_arr {1, 2, 3, 4};
    cout << my_arr.front() << endl;
    cout << my_arr.at(3) << endl;
    cout << my_arr[1] << endl;
    cout << my_arr.back() << endl;
}