#pragma once
#include<string>
#include<iostream>
#include<map>
using namespace std;
template <typename T>
class Stack {
	size_t size;
	T* mem;
	T top;
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
	size_t size() {
		return size;
	}
	bool Is_Empty() {

		return top == -1;
	}
	bool Is_Full() {

		return top == size - 1;
	}
	void Push(const T& val) {
		if (Is_Full()) throw - 1;
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