//
// Created by waff on 3/27/20.
//

#ifndef UNTITLED5_ARRAY_H
#define UNTITLED5_ARRAY_H

class Array {
private:
    int* arr = nullptr;
    size_t _size{};

    friend std::ostream& operator<< (std::ostream&, const Array&);

public:
    explicit Array (size_t n) {
        arr = new int[_size = n];

        for (auto i = 0; i < _size; ++i) {
            arr[i] = 0;
        }

        std::cout << "\033[36m[DEBUG]\033[37m Constructor called (" << this << ", " << std::addressof(arr) << ")\033[0m\n";
    }

    Array (const Array& original) {
        std::cout << "\033[36m[DEBUG]\033[37m Copy constructor called (" << this << ", " << std::addressof(arr) << ")\033[0m\n";
        arr = new int[_size = original.size()];

        for (auto i = 0; i < _size; ++i) {
            arr[i] = original.get(i);
        }
    }

    Array& operator= (const Array& original) {
        std::cout << "\033[36m[DEBUG]\033[37m = operator called (" << this << ", " << std::addressof(arr);
        delete[] arr;
        arr = new int[_size = original.size()];
        std::cout << std::addressof(arr) << ")\033[0m\n";

        for (auto i = 0; i < _size; ++i) {
            arr[i] = original.get(i);
        }

        return *this;
    }

    // index > i > idx
    int& operator[] (int index) {
        return arr[index];
    }

    ~Array () {
        std::cout << "\033[36m[DEBUG]\033[37m Destructor called (" << this << ", " << std::addressof(arr) << ")\033[0m\n";
        delete[] arr;
    }

    void set (size_t index, int item) {
        if (index > _size - 1) {
            throw std::out_of_range("Index exceeds maximum array size");
        }

        arr[index] = item;
    }

    int get (size_t index) const {
        if (index > _size - 1) {
            throw std::out_of_range("Index exceeds maximum array size");
        }

        return arr[index];
    }

    int size () const {
        return _size;
    }

    std::string toJSON () const {
        std::string res = "[";
        for (auto i = 0; i < _size; ++i) {
            if (i != 0) {
                res += ", ";
            }

            res += std::to_string(arr[i]);
        }

        return res + "]";
    }

    void print () {
        std::cout << toJSON() << "\n";
    }
};

// RIP... AND... TEAR...
// As one brave man (not) once said...
// How can one use multiple languages when writing code? No way I'll mix the languages there...
long long sum (Array arr) {
    long long sum = 0;
    for (auto i = 0; i < arr.size(); ++i) {
        sum += arr.get(i);
    }

    return sum;
}

Array create (size_t size) {
    Array array(size);
    return array;
}

std::ostream& operator<< (std::ostream& ostream, const Array& array) {
    return ostream << array.toJSON();
}

#endif //UNTITLED5_ARRAY_H
