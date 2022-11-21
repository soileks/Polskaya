#pragma once
#include<string>
#include<iostream>
#include<map>
using namespace std;
template <typename T>
class Stack {
	size_t size;
	T* mem;
	int top;
public:
	Stack(size_t s = 1) {

		size = s;
		top = -1;
		mem = new T[size];
	}
	Stack(const Stack& st)
	{
		top = st.top;
		size = st.size;
		copy(st.mem, st.mem + size, mem);
	}
	size_t Size() {
		return top + 1;
	}
	bool Is_Empty() {

		return top == -1;
	}
	bool Is_Full() {

		return top == size - 1;
	}
	void Push(const T& val)
	{
		if (top == size - 1)
		{
			T* tmp = new T[size * 2];
			copy(mem, size + mem, tmp);
			delete[] mem;
			mem = tmp;
			size *= 2;
		}
		mem[++top] = val;
	}
	T Pop() {
		if (Is_Empty())
		{
			throw - 2;
		}
		T tmp = mem[top];
		top--;
		return tmp;
	}
	T Top()
	{
		if (Is_Empty())
		{
			cout << "not found" << endl;
			throw - 3;
		}
		return mem[top];
	}

	friend ostream& operator << (ostream& ostr, Stack<T>& st) {
		for (int i = 0; i < st.size(); i++) {
			ostr << st.mem[i] << " ";
		}
		return ostr;
	}


	~Stack()
	{
		delete[] mem;
	}
};