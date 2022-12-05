#pragma once
#include<string>
#include<iostream>
#include<map>
#include"Stack.h"
//#include"Polsk.h"

using namespace std;

enum  TypeElement {
	Operation,
	Value,
	None

};

class Lexema {
	string str;  //строковое описание того, что внутри лексемы
	TypeElement type; //метка(что это за элемент)
public:
	Lexema() : type(None) {};
	Lexema(string _str, TypeElement _type) : str(_str), type(_type) {}; // возможно надо заменить operation 
	Lexema(const Lexema& p) : str(p.str), type(p.type) {};
	Lexema& operator=(const Lexema& p) {
		if (this == &p) {
			return *this;
		}
		str = p.str;
		type = p.type;
		return *this;
	}
	string getStr() { return str; }
	TypeElement getType() { return type; }
	friend ostream& operator << (ostream& out, Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};

//queue <Lexema> lex(string input) { // на вход поступает строчка, которую мы хотим анализировать
//	queue<Lexema>res;
//	input += ' ';
//	int i = 0;  //текущий обозреваемый символ в строке
//	string tmp = ""; //накапливаемое число (например, при сложении получается число)
//	string op = "+-*/()";
//	string sep = " \n\t";
//	int state = 0;//состояние в котором я нахожусь 
//	for (i = 0; i < input.size(); i++) {
//		char c = input[i]; //символ обозреваемый сейчас в строчке
//		int fres; //
//		switch (state)//свитч говорит нам, что вы делаем при каждом состоянии
//		{
//		case 0: // операция
//			if (c >= '0' && c <= '9') {
//				tmp = c;
//				state = 1;//переходим в состояние  1 ,которое говорит , что мы сейчас пытаемся распознать число
//				break;
//			}
//			fres = op.find(c);//в строке операций ищем текущий символ(вернет индекс в массиве символов) .Если не нашли символ с, то это не операция
//			if (fres >= 0) {
//				tmp = c;//переводим символ в строчку
//				Lexema l(tmp, Operation);
//				res.push(l);//помещаем в очередь, которая используется как выходной поток
//				state = 0;
//				break;
//			}
//			break;
//		case 1: // число
//			if (c >= '0' && c <= '9') {//
//				tmp += c;//прибавляем символ к строчке
//				state = 1;
//				break;
//			}
//			fres = op.find(c);//проверяем встретили ли операцию(ищем в строке операций)
//			if (fres >= 0) {//если операция
//				Lexema l1(tmp, Value);//помещаем накопленное число в очередь
//				res.push(l1);
//				tmp = c;
//				Lexema l2(tmp, Operation);//операцию кладем в очередь
//				res.push(l2);
//				state = 0;
//				break;
//			}
//			fres = sep.find(c);//проверяем на то, что встретили разделитель
//			if (fres >= 0) {
//				Lexema l(tmp, Value);//число помещаем в очередь
//				res.push(l);
//				state = 0;
//				break;
//			}
//			break;
//		}
//	}
//	return res;
//}
//
//void print(queue <Lexema> t) {//печать очереди
//	while (!t.empty()) {
//		cout << t.front() << endl;
//		t.pop();
//	}
//}

template <typename T>
class Queue {
private:
	size_t start;
	size_t end;
	T* p;
	size_t size;
	size_t next(size_t i) { return ((i + 1) % size); }

	void Add()
	{
		T* pp = new T[size * 2];
		int j = 1;
		for (size_t i = start; i != next(end); i = next(i))
		{
			pp[j] = p[i];
			j++;
		}
		delete[] p;
		p = pp;
		end = size - 1;
		size *= 2;
		start = 1;
	}

public:

	//Queue(){}

	Queue(size_t s = 1)
	{
		size = s;
		p = new T[size];
		end = 0;
		//end = ((s-1) % size);
		start = next(end);
	}
	size_t Size() { return size; }
	Queue(const Queue<T>& q)
	{
		size = q.size;
		end = q.end;
		start = q.start;
		p = new T[size]{};
		for (int i = start; i != next(end); i = next(i)) {
			p[i] = q.p[i];
		}
	}

	bool Is_Empty()
	{
		if (next(end) == start)
			return true;
		return false;
	}
	bool Is_Full() {
		if (next(next(end)) == start)
		{
			return true;
		}
		return false;
	}
	/*void Add()
	{
		T* pp = new T[size * 2];

		for (size_t i = 0; i < size; i++)
		{
			pp[i] = p[i];

		}
		end = size;
		delete[] p;
		p = pp;
		size *= 2;
	}*/
	
	T& operator[](int index)
	{
		return p[index];
	}
	


	void Push(T val) {
		if (Is_Full())
		{
			//throw - 1;

			Add();
		}
		end = next(end);
		p[end] = val;
	}
	Queue<T>& operator=(const Queue<T>& qu) {
		if (this == &qu)
			return *this;
		if (size > 0)
			delete[]p;
		size = qu.size;
		end = qu.end;
		start = qu.start;
		p = new T[size]{};
		for (int i = start; i != next(end); i = next(i)) {
			p[i] = qu.p[i];
		}
		return *this;
	}


	void Pop() {

		start = next(start);

	}
	T  Top() {

		T v = p[start];

		return v;
	}

	friend ostream& operator <<(ostream& out, Queue<T>& q)
	{
		if (q.Is_Empty())
		{
			out << "Queue is Empty!" << endl;
			return out;
		}
		for (int i = q.start; i != q.next(q.end); i = q.next(i))
		{
			out << q.p[i] << endl;
		}
		return out;
	}

	~Queue()
	{
		if (size != 0)
			delete[] p;
	}




};

Queue<Lexema>que(string input) {
	size_t i = 0;
	string tmp = "";
	string op = "+-*/()";
	string sep = " \n\t";
	int state = 0;

	Queue<Lexema> res;
	input += ' ';
	for (i = 0; i < input.size(); i++) {
		char c = input[i]; //символ обозреваемый сейчас в строчке
		int fres;
		switch (state)//свитч говорит нам, что вы делаем при каждом состоянии
		{
		case 0: // операция
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;//переходим в состояние  1 ,которое говорит , что мы сейчас пытаемся распознать число
				break;
			}
			fres = op.find(c);//в строке операций ищем текущий символ(вернет индекс в массиве символов) .Если не нашли символ с, то это не операция
			if (fres >= 0) {
				tmp = c;//переводим символ в строчку
				Lexema l(tmp, Operation);
				res.Push(l);//помещаем в очередь, которая используется как выходной поток
				state = 0;
				break;
			}
			break;
		case 1: // число
			if (c >= '0' && c <= '9') {//
				tmp += c;//прибавляем символ к строчке
				state = 1;
				break;
			}
			fres = op.find(c);//проверяем встретили ли операцию(ищем в строке операций)
			if (fres >= 0) {//если операция
				Lexema l1(tmp, Value);//помещаем накопленное число в очередь
				res.Push(l1);
				tmp = c;
				Lexema l2(tmp, Operation);//операцию кладем в очередь
				res.Push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);//проверяем на то, что встретили разделитель
			if (fres >= 0) {
				Lexema l(tmp, Value);//число помещаем в очередь
				res.Push(l);
				state = 0;
				break;
			}
			break;
		}
	}
	

	return res;
}
