#include "Vector.h"
#include <iostream>
void swap(int *a, int *b) {
    int *t = a;
    a = b;
    b = t;
}
void swap(int &num1, int &num2) {
    int t = num1;
    num1 = num2;
    num2 = t;
}
Vector::Vector(int size) 
    :size{size} {
        if(size <= 0)
            size = 1;
    capacity = size + 10;
    a = new int[capacity];
}
bool Vector::set(int index, int num) {
    if(index >= 0 && index < size) {
        *(a + index) = num;
        return 1;
    }
    return 0;
}
int Vector::get(int index) const {
    if(index >= 0 &&index < size)
        return *(a + index);
    return -1;
}
void Vector::print() const{
    for(int i = 0; i < size; ++i) 
        std::cout << *(a + i) << ' ';
    std::cout << std::endl;   
}
int Vector::find(int num) const{
    for(int i = 0; i < size; ++i)
        if(num == *(a + i))
            return i;
    return -1;
}
void Vector::AddNumber(int number) {
    if(size == capacity) {
        Vector::expand_capacity();
    }
    a[size++] = number;
}
void Vector::insert(int num, int index) {
    if(index < 0 && index > size)//we add the
        return;
    if(index == size)
        AddNumber(num);
    else {
        for(int i = size - 1; i >= index; --i) {
            a[i+1] = a[i];
        }
        a[index] = num;
        size++;
    }
}
Vector::~Vector() {
    delete []a;
    a = nullptr;        
}


void Vector::expand_capacity() {
		// Double the actual array size
		capacity *= 2;
		std::cout << "Expand capacity to "
				<< capacity << "\n";
		int *arr2 = new int[capacity] { };
		for (int i = 0; i < size; ++i)
			arr2[i] = a[i];	// copy data

		swap(a, arr2);
		delete[] arr2;
	}
// void Vector::expand_capacity() {
//     capacity *= 2;
//     int *buff = new int[capacity];
//     for(int i = 0; i < size; ++i) 
//         buff[i] = a[i];
//     swap(a, buff);
//     delete [] buff;
// }

void Vector::right_rotation() {
    //we have an extra size so
    for(int i = size - 1; i >= 0; --i) {
        a[i+1] = a[i];
    }
    a[0] = a[size];
}
void Vector::left_rotation() {
    a[size] = a[0];
    for(int i = 0; i < size; ++i)
        a[i] = a[i + 1];
}
//shift with num times
void Vector::right_rotation(int num) {
    num %= size;
    while(num--) {      
        Vector::right_rotation();
    }
}
//deleting position
void Vector::pop(int idx) {
    for(int i = idx; i < size; ++i) 
        a[i] = a[i + 1];
    size--;
}

//find and shift
int Vector::find_transpotion(int num) {
    int ind = Vector::find(num);
    if(ind == -1)
        return -1;
    if(ind == 0) {
        swap(a[0], a[size-1]);
        return size-1;
    }
    swap(a[ind], a[ind-1]);
    return ind-1;
}

int &Vector::operator[](int idx) {
    return *(a + idx);
}