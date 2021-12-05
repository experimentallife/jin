#ifndef WEKTOR_H_
#define WEKTOR_H_

template <typename T> std::ostream & operator<< (std::ostream & str, const Wektor<T> & w);

template <typename T>
class Wektor
{
	T * values;
	int size;
	int capacity;

public:
	Wektor();
	Wektor(int);
	Wektor(const Wektor &);
	~Wektor();

	int pobierzWielkosc() { return size; }
	void dodaj(T&);
	void dodaj(T*);
	int szukaj(const T&);
	bool usun(T&);
	bool zamien(T&, T&);
	bool zamien(T*&, T*&);
	bool czyPusty();

	Wektor & operator=(const Wektor&);
	T & operator[](int idx) const;

	friend std::ostream & operator<< <T> (std::ostream&, const Wektor<T>&);
};




template <typename T>
Wektor<T>::Wektor()
{
	values = new T[16];
	size = 0;
	capacity = 16;
}




template <typename T>
Wektor<T>::Wektor(int val)
{
	T = new T(val);
	size = 0;
	capacity = val;
}




template <typename T>
Wektor<T>::Wektor(const Wektor & w)
{
	this->size = w->size;
	this->capacity = w->capacity;
	for (int i = 0; i < this->size; ++i)
		this->values[i] = w->values[i];
}




template <typename T>
Wektor<T>::~Wektor()
{
	delete[] values;
	values = nullptr;
	size = 0;
	capacity = 0;
}




template <typename T>
void Wektor<T>::dodaj(T & val)
{
	
	
	
	
	
	
	if (size >= capacity && capacity > 0)
	{
		capacity = capacity * 2;
		T * temp = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = this->values[i];
		}
		if (values) delete[] values;
		values = temp;
	}

	values[size] = val;
	++size;

	return;
}




template <typename T>
void Wektor<T>::dodaj(T * val)
{
	
	
	
	
	
	
	if (size >= capacity && capacity > 0)
	{
		capacity = capacity * 2;
		T * temp = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = this->values[i];
		}
		if (values) delete[] values;
		values = temp;
	}

	values[size] = *val;
	++size;

	return;
}




template <typename T>
int Wektor<T>::szukaj(const T & val)
{
	
	
	
	
	for (int i = 0; i < size; ++i)
	{
		if (values[i] == val)
			return i;
	}

	return -1;
}




template <typename T>
bool Wektor<T>::usun(T & val)
{
	
	
	if (szukaj(val) == -1) return false;

	
	
	
	
	
	
	if (szukaj(val) >= 0 && szukaj(val) < size)
	{
		for (int i = szukaj(val) + 1; i < size; ++i)
			values[i - 1] = values[i];
		--size;
		return true;
	}

	
	
	return false;
}




template <typename T>
bool Wektor<T>::zamien(T & val1, T & val2)
{
	
	
	
	if (szukaj(val1) <= -1 && szukaj(val2) <= -1) return false;

	T temp;

	
	
	if (szukaj(val1) >= 0 && szukaj(val1) < size &&
		szukaj(val2) >= 0 && szukaj(val2) < size)
	{
		temp = val1;
		values[szukaj(val1)] = val2;
		values[szukaj(val2)] = temp;

		return true;
	}

	
	return false;
}




template <typename T>
bool Wektor<T>::zamien(T * & val1, T * & val2)
{
	
	
	
	if (szukaj(val1) <= -1 && szukaj(val2) <= -1) return false;

	T * temp = nullptr;

	
	
	if (szukaj(val1) >= 0 && szukaj(val1) < size &&
		szukaj(val2) >= 0 && szukaj(val2) < size)
	{
		*temp = *val1;
		*(values[szukaj(val1)]) = *val2;
		*(values[szukaj(val2)]) = *temp;

		return true;
	}

	
	return false;
}




template <typename T>
bool Wektor<T>::czyPusty()
{
	if (size <= 0) return true;
	else return false;
}




template <typename T>
Wektor<T> & Wektor<typename T>::operator=(const Wektor & w)
{
	
	
	
	

	delete[] values;
	this->w = new T[w.size];
	this->size = w->size;

	for (int i = 0; i < size; ++i)
		this->values[i] = w->values[i];

	return *this;
}




template <typename T>
T & Wektor<T>::operator[](int idx) const
{
	

	if (idx >= 0 && idx < size)
		return values[idx];
}




template <typename T>
std::ostream & operator<< (std::ostream & str, const Wektor<T> & w)
{
	for (int i = 0; i < w.size; ++i)
		str << i + 1 << ". " << w.values[i] << std::endl;
	str << std::endl;

	return str;
}


#endif