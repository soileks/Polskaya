#pragma once
#include"Stack.h"
#include"Polsk.h"
#include"Lexema_and_Queue.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class polsk {

	int prior = 0;
	string in;
	vector<Lexema> vec;
	string op = "+-/*";
	Stack<Lexema> st;
	Queue<Lexema> result;

public:
	polsk(string input) {
		in = input;

		result = que(in);
	};
	/*void prioirity() {
		map<char, int> operations;
		operations.emplace('*', 2);
		operations.emplace('/', 2);
		operations.emplace('+', 1);
		operations.emplace('-', 1);
		operations.emplace('(', 0);
		operations.emplace(')', 0);
	}*/



	void transl() {
		//char с;

		map<char, int> operations;
		operations.emplace('*', 2);
		operations.emplace('/', 2);
		operations.emplace('+', 1);
		operations.emplace('-', 1);
		operations.emplace('(', 0);
		operations.emplace(')', 0);

		while (!result.Is_Empty()) {
			Lexema l = result.Pop();
			//vec.push_back(l);
			switch (l.getType()) {

			case Operation: {

				char sign = l.getStr()[0];

				switch (sign) {

				case '(': {

					//prior = operations.find('(')->second;
					st.Push(l);
				}
						break;
				case ')':
				{
					if (!st.Is_Empty()) {


						if (st.Top().getStr() != "(")
						{
							while ((st.Top().getStr() != "(") || !st.Is_Empty()) {

								vec.push_back(st.Pop());

							}
						}
						if (st.Top().getStr() == "(") {

							st.Pop();
						}
						if (st.Is_Empty()) throw - 4;

					}
					else {
						throw - 4;
					}

					//prior = operations.find(')')->second;
				}
				break;
				case '*':case'/':
				{

					string c = st.Top().getStr();
					char p = c[0];
					prior = operations[p];
					if (prior == 2) {
						vec.push_back(st.Pop());
					}

					else {
						st.Push(l);
					}
				}
				break;

				/*if ((st.Top().getStr() == "*")|| (st.Top().getStr() == "/")) {
						vec.push_back(st.Pop());
					}*/

				case '+':case'-':
				{

					string c = st.Top().getStr();
					char p = c[0];
					prior = operations[p];

					while (prior == 2 || prior == 1) {
						vec.push_back(st.Pop());
						c = st.Top().getStr();
						p = c[0];
						prior = operations[p];
					}

					if (st.Is_Empty() || prior == 0) {
						st.Push(l);

					}
				}
				break;

				}
			}
						  break;
			case Value:
				vec.push_back(l);
				break;
			}
		}
	}

	double calc_stream() {
		for (int i = 0; !vec.empty(); i++) {
			if (vec[i].getType() == Value) {
				st.Push(vec[i]);
			}
			if (vec[i].getType() == Operation) {
				string a = st.Pop().getStr();
				string b = st.Pop().getStr();
				size_t* pos = 0;

				double a_d = stod(a, pos); //преобразование строк в double
				double b_d = stod(b, pos);
				char sign = vec[i].getStr()[0];
				switch (sign) {
				case '*': {
					size_t* pos = 0;
					double res = a_d * b_d;
					string str = to_string(res);
					//string str =  wcstod(res,pos);
					st.Push(str);
				}
						break;
				case '/': {
					size_t* pos = 0;
					double res = a_d / b_d;
					string str = to_string(res);
					//string str =  wcstod(res,pos);
					st.Push(str);
				}
						break;
				case '+': {
					size_t* pos = 0;
					double res = a_d + b_d;
					string str = to_string(res);
					//string str =  wcstod(res,pos);
					st.Push(str);
				}
						break;
				case '-': {
					size_t* pos = 0;
					double res = a_d - b_d;
					string str = to_string(res);
					//string str =  wcstod(res,pos);
					st.Push(str);
				}
						break;
				}

			}
		}
		size_t* pos = 0;

		double res_d = stod(st.Top().getStr(), pos);
		cout << " At the top of the stack:  " << res_d << endl;
		return res_d;
	}

	//лексический разбиват на лексемы. Синтаксический понимает принадлежит языку или нет ( проверяет что нет ошибок, перевод в обратную польскую)




};
