#pragma once
#include <cstddef> //??
#include <iostream>
#include<algorithm> // sort

template<typename T>

class Vector
{
public:
	Vector(std::size_t size); // конструктор

	~Vector(); // деструктор

	Vector(const Vector& vector); // конструктор копирования

	Vector& operator=(const Vector& vector); // оператор копирующего присваивания  

	Vector(Vector&& vector) noexcept; //Конструктор перемещения

	Vector& operator=(Vector&& vector) noexcept;

	void swap(Vector& vector) noexcept;

	T& operator[](std::size_t index);

	

	std::size_t getSize() const;

	Vector& pushBack(const T value);

	Vector& popBack();

	Vector& sort();

	friend std::ostream& operator<<(std::ostream& stream, Vector& vector)
{
	for (std::size_t i = 0; i < vector.getSize(); i++)
	{
		stream << vector[i] << " ";
	}
	stream << "\n";
	return stream;

}


private:
	std::size_t size_{};
	T *array_{nullptr};
};


template<typename T>
Vector<T>::Vector(std::size_t size) // конструктор 
{
	size_ = size; // before value
	if (size > 0) // before value
	{
		size_ = size;
		try
		{
			array_ = new T[size]; // before value

			for (std::size_t i = 0; i < size; i++)
			{
				array_[i] = T();
			}
		}
		catch (const std::bad_alloc&)
		{
			delete[] array_;
			throw;
		}
	}
}

template<typename T>

Vector<T>::~Vector()  // деструктор
{
	delete[] array_;
	size_ = 0;
}

template<typename T>

Vector<T>::Vector(const Vector& vector) // конструктор копирования
{

	try
	{
		size_ = vector.size_;
		array_ = new T[vector.size_];

		for (std::size_t i = 0; i < size_; i++)
		{
			array_[i] = vector.array_[i];
		}
	}
	catch (const std::bad_alloc&)
	{
		delete[] array_;
		throw;
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) // оператор присувающего копирования
{
	if (this != &vector)
	{
		Vector<T> tmp(vector);
		swap(tmp);
	}
	return *this;
}

template<typename T>
void Vector<T>::swap(Vector& vector) noexcept	// для сохранения целостности данных при возникновении ошибки
{
	std::swap(array_, vector.array_);
	std::swap(size_, vector.size_);
}


template<typename T>
Vector<T>::Vector(Vector&& vector) noexcept //Конструктор перемещения 
{
	this->array_ = vector.array_;
	this->size_ = vector.size_;

	vector.array_ = nullptr;
	vector.size_ = 0;

}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& vector) noexcept // оператор перемещабщего пристваивания
{
	if (this != &vector)
	{
		Vector<T> tmp(static_cast<Vector&&>(vector)); // vector -> R-value
		swap(tmp);
	}

	return *this;
}

template<typename T>
T& Vector<T>::operator[](std::size_t index) // обращение к элементам
{
	if (index >= size_)
	{
		throw std::invalid_argument("Invalid input array size");
	}
	return array_[index];
}

template<typename T>
std::size_t Vector<T>::getSize() const
{
	return size_;
}


template<typename T>
Vector<T>& Vector<T>::pushBack(const T value) 
{
	Vector<T> tmp((size_ + 1));
	for (std::size_t i = 0; i < size_; i++)
	{
		tmp.array_[i] = array_[i];
	}
	tmp.array_[size_] = value;

	//ector<T> tmp2(static_cast<Vector&&>(tmp)); // vector -> R-value
	swap(tmp);

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::popBack()
{
	Vector<T> tmp((size_ - 1));
	for (std::size_t i = 0; i < (size_ -1); i++)
	{
		tmp.array_[i] = array_[i];
	}

	Vector<T> tmp2(static_cast<Vector&&>(tmp)); // vector -> R-value
	swap(tmp2);

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::sort()
{
	std::sort(array_, array_ + this->getSize());
	return *this;
}