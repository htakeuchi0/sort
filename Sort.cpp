#include "Sort.h"
#include <iostream>

// コンストラクタ
// 指定された配列サイズの乱数配列を生成する 
Sort::Sort(size_t size):
	size_(size),
	type_(ArrayType::kRandom)
{
	GenerateRandomArray();
}

// コンストラクタ
// 指定された配列サイズと配列タイプから配列を生成する
Sort::Sort(size_t size, ArrayType type):
	size_(size),
	type_(type)
{
	switch(type){
	case ArrayType::kRandom:
		GenerateRandomArray();
		break;

	case ArrayType::kDistinct:
		GenerateDistinctArray();
		break;

	case ArrayType::kOrdered:
		GenerateOrderedArray();
		break;

	default:
		break;
	}
}

// コンストラクタ
// 指定された配列をコピーする
Sort::Sort(int *arr, size_t size):
	size_(size),
	type_(ArrayType::kConstant)
{
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		array_[i] = arr[i];
		org_array_[i] = array_[i];
	}
}

// コピーコンストラクタ
Sort::Sort(const Sort& sort) {
	size_ = sort.Size();
	
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	sort.Array(array_);

	type_ = sort.Type();
	
	for (size_t i = 0; i < size_; i++) {
		org_array_[i] = array_[i];
	}
}

// デストラクタ
// メモリを解放する
Sort::~Sort() {
	delete[] array_;
	array_ = nullptr;

	delete[] org_array_;
	org_array_ = nullptr;
}

// 初期化
bool Sort::Initialize() {
	// 配列に登録がない場合は乱数配列を生成する
	if (array_ == nullptr || org_array_ == nullptr) {
		std::random_device rand_device;
		for (size_t i = 0; i < size_; i++) {
			array_[i] = rand_device() % size_;
			org_array_[i] = array_[i];
		}
	}
	// 登録がある場合は配列を初期状態に戻す
	else {
		for (size_t i = 0; i < size_; i++) {
			array_[i] = org_array_[i];
		}
	}
	return true;
}

// 配列のサイズを返す
size_t Sort::Size() const {
	return size_;
}

// 配列のタイプを返す
ArrayType Sort::Type() const {
	return type_;
}

// 配列のサイズを設定する
// 与えられた大きさの配列を再生成する
bool Sort::SetSize(size_t size) {
	// 定数配列の場合は設定できない
	if (type_ == ArrayType::kConstant) {
		std::cerr << "サイズを変更できません" << std::endl;
		return false;
	}
	
	// サイズの設定
	size_ = size;

	// メモリの解放
	if (array_){
		delete[] array_;
		array_ = nullptr;
	}

	if (org_array_) {
		delete[] org_array_;
		org_array_ = nullptr;
	}

	// 配列を再生成
	switch(type_){
	case ArrayType::kRandom:
		GenerateRandomArray();
		break;

	case ArrayType::kDistinct:
		GenerateDistinctArray();
		break;

	case ArrayType::kOrdered:
		GenerateOrderedArray();
		break;

	default:
		break;
	}
	
	return true;	
}

// データメンバの配列を引数の配列にコピーする
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

// 乱数配列の生成
void Sort::GenerateRandomArray()
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

// すべての要素が異なる乱数配列の生成
void Sort::GenerateDistinctArray() {
	array_ = new int[size_];
	if (array_ == nullptr){
		return;
	}

	org_array_ = new int[size_];
	if (org_array_ == nullptr){
		return;
	}

	// すべての要素が異なる配列
	for (size_t i = 0; i < size_; i++) {
		array_[i] = i;
	}

	// 配列の先頭からj個の要素をランダムに取り出し
	// j+1番目の要素と交換してシャッフルする
	std::random_device rand_device;
	for (size_t j = size_ - 1; j >= 1; j--) {
		int i = rand_device() % j;

		int tmp = array_[i];
		array_[i] = array_[j];
		array_[j] = tmp;
	}

	// ソート前の配列を保持
	for (size_t i = 0; i < size_; i++) {
		org_array_[i] = array_[i];
	}
}

// ソート済み配列を生成
void Sort::GenerateOrderedArray() {
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
