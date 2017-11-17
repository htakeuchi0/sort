#include "Sort.h"
#include <iostream>

Sort::Sort(size_t size):
	size_(size)
{
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	std::random_device rand_device;
	for (int i = 0; i < size_; i++) {
		array_[i] = rand_device() % (size_ * 2);
		org_array_[i] = array_[i];
	}
}

Sort::Sort(int *arr, size_t size):
	size_(size)
{
	array_ = new int[size_];
	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	for (int i = 0; i < size_; i++) {
		array_[i] = arr[i];
		org_array_[i] = array_[i];
	}
}

Sort::~Sort() {
	delete[] array_;
	array_ = nullptr;

	delete[] org_array_;
	org_array_ = nullptr;
}

bool Sort::Initialize() {
	if (array_ == nullptr || org_array_ == nullptr) {
		std::random_device rand_device;
		for (int i = 0; i < size_; i++) {
			array_[i] = rand_device() % (size_ * 2);
			org_array_[i] = array_[i];
		}
	}
	else {
		for (int i = 0; i < size_; i++) {
			array_[i] = org_array_[i];
		}
	}
	return true;
}

size_t Sort::Size() const {
	return size_;
}

void Sort::Array(int *arr) const {
	if (arr == nullptr || array_ == nullptr) {
		return;
	}

	for (int i = 0; i < size_; i++) {
		arr[i] = array_[i];
	}
}

// data‚Ì—v‘f‚ð•\Ž¦
void Sort::Show() const {
	for (size_t i = 0; i < size_; i++) {
		std::cout << array_[i] << ", ";
	}
	std::cout << std::endl;
}
