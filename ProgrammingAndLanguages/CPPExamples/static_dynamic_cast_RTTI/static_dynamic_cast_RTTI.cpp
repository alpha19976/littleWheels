#include <iostream>
#include <typeinfo>

using namespace std;

class Base 
{
	int a;
public:
    virtual void f() {cout<<"Base::f()"<<endl;}

};

class Derive: public Base
{
	int a1;
public:
    virtual  void f() {cout<<"Derive::f()"<<endl;}
    virtual  void f2() {cout<<"Derive::f1()"<<endl;}

};

class Derive2: public Base {
	int a2;
};

typedef unsigned long DWORD;

//����RTTITypeDescriptor�ṹ�����õ�RTTITypeDescriptor������
struct RTTITypeDescriptor
{
    DWORD ptrToVTable;
    DWORD spare;
    char name[];
};

//����RTTICompleteObjectLocator�ṹ�����õ���RTTICompleteObjectLocator����
struct RTTICompleteObjectLocator
{
    DWORD signature; //always zero ?

    DWORD offset;    //offset of this vtable in the complete class

    DWORD cdOffset;  //constructor displacement offset

    struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class

    int * ptr; //struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy
};

void print_type(Base* pbase) {
	const type_info& typeinfo = typeid(pbase);
	cout << "typeinfo name: " << typeinfo.name() << endl
		<< "typeinfo hashcode: " << typeinfo.hash_code() <<endl
		<< "typeinfo rawname" << typeinfo.raw_name() << endl;
	if(NULL != dynamic_cast<Derive*>(pbase)) {
		cout << "type identification by test dynamic_cast: Derive" << endl;
	} else if(NULL != dynamic_cast<Derive2*>(pbase)) {
		cout << "type identification by test dynamic_cast: Derive2" << endl;
	} else {
	}
}

int main()
{
	cout << endl << endl << "---Test static cast---" << endl;
	//static_cast
    Base *pbase1  = new Derive();
    Derive* pderive1 = static_cast<Derive *>(pbase1);
    pderive1->f(); // Derive::f()
    
    Base* pbase2 = new Base();
	//�������̬����ת�����ᱨ��
    Derive * pderive2 = static_cast<Derive *>(pbase2);
    pderive2->f();  // Base::f()
	//�ڵ���ʱ����
    //pderive2->f2(); // ȥ��ע�ͣ���throw exception "Access violation reading"

    delete pbase1;
    delete pbase2;

	cout << endl << endl << "---Test dynamic cast---" << endl;
	//dynamic_cast
	Base *pbase3 = new Derive();
	//down-cast : converting a base-class pointer (reference) to a derived-class pointer (reference)
	Derive* pderive3 = dynamic_cast<Derive *>(pbase3); 
	pderive3->f(); // Derive::f()

	Base* pbase4 = new Base();
	//down-cast
	//��������̬����ת��ʱ��dynamic_cast�������ͼ�飬���ֲ���ת�����ͷ���null
	Derive * pderive4 = dynamic_cast<Derive *>(pbase4); 

	if ( pderive4 ) // NULL
	{
		//��Ϊpderive4��NULL���������ﲻ��ִ��
		pderive4->f();
		pderive4->f2();
	}

	delete pbase3;
	delete pbase4;

	cout << endl << endl << "---Test RTTI---" << endl;
	Base* pbase5 = new Derive();
	print_type(pbase5); //type identification by test dynamic_cast: Derive

	Base* pbase6 = new Derive2();
	print_type(pbase6); //type identification by test dynamic_cast: Derive2

	delete pbase5;
	delete pbase6;

	cout << endl << endl << "---Test RTTI Type Descriptor---" << endl;
	
	//Derive��һ�������ָ��
	Base *pbase7 = new Derive();
    
	//��ָ������ָ������ת��ָ��������ָ������
	int *objptr = (int *)pbase7;

	//�Ӷ����ַָ����ڴ��еõ��麯�����ָ��
    int *vftptr = (int *)(*objptr); 

	//�õ�RTTICompleteObjectLocator��ָ��
    RTTICompleteObjectLocator * rttiObjLoc = (RTTICompleteObjectLocator *)(*((int*)(vftptr - 1)));
	
	//�õ�RTTITypeDescriptor��ָ��
	RTTITypeDescriptor * rttiTypeDes = (RTTITypeDescriptor *) rttiObjLoc->pTypeDescriptor;

	//����RTTITypeDescriptor��������raw_name
    cout<< "typeinfo rawname by pointer: " << rttiTypeDes->name <<endl;

	//���ñ�׼���typeid�����õ�������raw_name
	const type_info& ti = typeid(*pbase7);
	cout << "typeinfo rawname by typeid: " << ti.raw_name() << endl;

	system("pause");
	return 0;
}