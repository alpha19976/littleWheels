#pragma once
class Car; //ǰ������
class Wheel
{
private:
	int id;
	static int count;
public:
	Wheel(void);
	~Wheel(void);
	void Run();

	Car * car; //ʹ����ָ��
};

