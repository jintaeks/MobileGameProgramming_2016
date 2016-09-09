// Algorithm.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

template<typename T, int STACK_SIZE>
class KStack
{
public:
	KStack() : m_sp(0)
	{
	}
	void Push(T data_);
	bool Pop(T& outData_);
	bool IsEmpty() const;
private:
	int m_sp;
	T m_data[STACK_SIZE];
};//class KStack

template<typename T, int STACK_SIZE>
void KStack<T, STACK_SIZE>::Push(T data_)
{
	m_data[m_sp] = data_;
	m_sp += 1;
}
template<typename T, int STACK_SIZE>
bool KStack<T, STACK_SIZE>::Pop(T& outData_)
{
	if (m_sp <= 0) return false;
	m_sp -= 1;
	outData_ = m_data[m_sp];
	return true;
}
template<typename T, int STACK_SIZE>
bool KStack<T, STACK_SIZE>::IsEmpty() const
{
	return m_sp == 0;
}

template<>
class KStack<char,100>
{
public:
	KStack() : m_sp(0)
	{
	}
	void Push(char data_){}
	bool Pop(char& outData_){ return false; }
	bool IsEmpty() const{ return false; }
private:
	int m_sp;
	char m_data[100];
};//class KStack

void main()
{
	KStack<int, 100> s;
	s.Push(3);
	s.Push(5);
	int data;
	const bool bIsPop = s.Pop(data);
	printf("%d\r\n", data);
}

