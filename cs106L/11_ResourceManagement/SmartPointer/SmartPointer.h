#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

/***********************
 * һ��C++����ָ���ʵ�� *
 ***********************/
template <typename T> class SmartPointer
{
public:
	// Conversion constructor
	explicit SmartPointer(T* memory);
	// Copy constructor
	SmartPointer(const SmartPointer& other);
	// Assignment operator
	SmartPointer<T>& operator = (const SmartPointer<T>& other);	
	// Destructor
	~SmartPointer(void);

	T& operator * () const;
	T* operator -> () const;
	T* get() const;
	size_t getShareCount() const;

	void reset(T* newres);

private:
	struct Intermediary {
		T* resource;
		size_t refCount;
	};
	Intermediary* data;

	void detach();
	void attach(Intermediary* other);
};


//ģ������Ҫʹ���ں���include��ʽ����ʵ�ֺ�ԭ�ͷ���һ��
template <typename T> SmartPointer<T>::SmartPointer(T* res) {
	data = new Intermediary;
	data->resource = res;
	data->refCount = 1;
}

template <typename T> SmartPointer<T>::~SmartPointer() {
	detach();
}

template <typename T> T& SmartPointer<T>::operator * () const {
	return *data->resource; //*(data->resource)
}

template <typename T> T* SmartPointer<T>::operator -> () const {
	return data->resource; //ָ��T�������ݵĵ�ַ
}

template <typename T> T* SmartPointer<T>::get() const {
	return data->resource;
}

template <typename T> size_t SmartPointer<T>::getShareCount() const {
	return data->refCount;
}

template <typename T> void SmartPointer<T>::detach() {
	--data->refCount;
    if(data->refCount == 0) {
		delete data->resource;
		delete data;
	}
}

template <typename T> void SmartPointer<T>::attach(Intermediary* to) {
	data = to;
	++data->refCount;
}

template <typename T> void SmartPointer<T>::reset(T* newres) {
	detach();
	data = new Intermediary;
	data->resource = newres;
	data->refCount = 1;
}

template <typename T> SmartPointer<T> ::SmartPointer(const SmartPointer& other) {
	attach(other.data); //sibling access
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator = (const SmartPointer& other) {
	//check for self-assignment
	if(this != &other) {
		detach();
		attach(other.data);	
	}
	return *this;
}

#endif