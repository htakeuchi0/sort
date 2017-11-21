#include "Sort.h"
#include <iostream>

void Sort::OrdinaryConstructor()
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
	for (size_t i = 0; i < size_; i++) {
		array_[i] = rand_device() % size_;
		org_array_[i] = array_[i];
	}
}

Sort::Sort(size_t size):
	size_(size),
	type_(ArrayType::kNormal)
{
	OrdinaryConstructor();
}

Sort::Sort(size_t size, ArrayType type):
	size_(size),
	type_(type)
{
	switch(type){
	case ArrayType::kNormal:
		OrdinaryConstructor();
		break;

	case ArrayType::kDistinct:
		DistinctConstructor();
		break;

	case ArrayType::kOrdered:
		OrderedConstructor();
		break;

	default:
		break;
	}
}

Sort::Sort(int *arr, size_t size):
	size_(size),
	type_(ArrayType::kNone)
{
	array_ = new int[size_];
	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	for (size_t i = 0; i < size_; i++) {
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
		for (size_t i = 0; i < size_; i++) {
			array_[i] = rand_device() % (size_ * 2);
			org_array_[i] = array_[i];
		}
	}
	else {
		for (size_t i = 0; i < size_; i++) {
			array_[i] = org_array_[i];
		}
	}
	return true;
}

size_t Sort::Size() const {
	return size_;
}

void Sort::SetSize(size_t size) {
	if (type_ == ArrayType::kNone) {
		std::cerr << "サイズを変更できません" << std::endl;
		return;
	}
	
	size_ = size;

	if (array_){
		delete[] array_;
		array_ = nullptr;
	}

	if (org_array_) {
		delete[] org_array_;
		org_array_ = nullptr;
	}


	switch(type_){
	case ArrayType::kNormal:
		OrdinaryConstructor();
		break;

	case ArrayType::kDistinct:
		DistinctConstructor();
		break;

	case ArrayType::kOrdered:
		OrderedConstructor();
		break;

	default:
		break;
	}
	
}

void Sort::Array(int *arr) const {
	if (arr == nullptr || array_ == nullptr) {
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		arr[i] = array_[i];
	}
}

// dataの要素を表示
void Sort::Show() const {
	for (size_t i = 0; i < size_; i++) {
		std::cout << array_[i] << ", ";
	}
	std::cout << std::endl;
}

void Sort::DistinctConstructor() {
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		array_[i] = i;
	}

	std::random_device rand_device;
	for (size_t j = size_ - 1; j >= 1; j--) {
		int i = rand_device() % j;

		int tmp = array_[i];
		array_[i] = array_[j];
		array_[j] = tmp;
	}

	for (size_t i = 0; i < size_; i++) {
		org_array_[i] = array_[i];
	}
}

void Sort::OrderedConstructor() {
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	std::random_device rand_device;
	for (size_t i = 0; i < size_; i++) {
		array_[i] = org_array_[i] = i;
	}
}
