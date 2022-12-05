#pragma once
#include"Stack.h"
#include<map>
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
	polsk(string& input) {
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

	void check() {
		/*int res_1;
		int res_2;
		for (int i = 0; i < result.Size() - 1; i++) {
			res_1 = op.find(result[i].getStr());
			res_2 = op.find(result[i+1].getStr());
			if (res_1 >= 0 && res_2 >= 0) {
				cout << "\n" << i+1;
					throw exception(" <-- (2 arithmetic expressions in a row on the position)");
			}
		}*/

		int res_1;
		int res_2;
		
		for (int i = 0; i < in.size()-1; i++) {
			res_1 = op.find(in[i]);
			res_2 = op.find(in[i + 1]);
			if (res_1 >= 0 && res_2 >= 0) {
				cout <<"\n" << i+2;
				//cout<<"number operation"<<
				throw exception(" <-- (the position of the operation in the array where the error is)");
			}
		}
	}

	void print_que() {
		cout << "\n";
		cout << result;
		//cout << que(in);
		cout << "\n";
	}

	void transl() {
		//char с;
		int pos=0;
		int tmp = 0;
		map<char, int> operations;
		operations.emplace('*', 2);
		operations.emplace('/', 2);
		operations.emplace('+', 1);
		operations.emplace('-', 1);
		operations.emplace('(', 0);
		operations.emplace(')', 0);

		while (!result.Is_Empty()) {

			Lexema l = result.Top();
			result.Pop();
			//vec.push_back(l);

			switch (l.getType()) {

			case Operation: {

				char sign = l.getStr()[0];

				switch (sign) {

				case '(': {

					st.Push(l);
					pos++;
					tmp++;
					
					break;
				}
						//break;
				case ')':
				{ pos++;
				tmp++;
					if (!st.Is_Empty()) {
						if (st.Top().getStr() != "(")
						{
							while ((st.Top().getStr() != "(") /*|| !st.Is_Empty()*/) {

								vec.push_back(st.Top());
								st.Pop();
								if (st.Is_Empty()) {
									if (pos % 2 != 0) {
										cout << "\nThe number of the bracket that does not have a pair: "<<pos;;
									}
									throw exception("\n does not exist ( ");
									break;
								}
							}
						}
						//if (st.Is_Empty()) throw "does not exist (";
						if (st.Top().getStr() == "(") {

							st.Pop();
							tmp -= 2;;
						}
						//if (st.Is_Empty()) throw "does not exist (";

					}

					else  {
						if (pos % 2 != 0) {
							cout << "the number of the bracket that does not have a pair: "<<pos;
							
						}
						
						throw exception(" \n does not exist ( ");
						
						
					}

					

					break;

				}
				//break;
				case '*':case'/':
				{
						while (!st.Is_Empty()) {

							string c = st.Top().getStr();
							//st.Pop();
							char p = c[0];
							//char p = st.Top().getStr()[0];
							prior = operations[p];
							if (prior == 2) {
								vec.push_back(st.Top());
								st.Pop();
							}
							else {
								st.Push(l);
								break;
							}
						}
						if (st.Is_Empty()) st.Push(l);
					
					break;
				}
				//break;

				case '+':case'-':
				{
					
					while (!st.Is_Empty()) {


						string c = st.Top().getStr();
						//st.Pop();
						char p = c[0];
						prior = operations[p];

						while (prior == 2 || prior == 1) {
							vec.push_back(st.Top());
							st.Pop();
							if (st.Is_Empty()) {
								//st.Push(l);
								break;
							}
							else {
								c = st.Top().getStr();
								p = c[0];
								prior = operations[p];
							}
						}


						if (st.Is_Empty() || prior == 0) {
							st.Push(l);
							break;
						}
					}
				
				//st.Push(l);
					break;
				}
				//break;

				}
				break;
			}
						  //break;
			case Value: {
				vec.push_back(l); }
					  break;

			}
			
		}
		
		if (pos % 2 != 0) {
			cout <<"\n" << pos;
			throw exception(" <-- the number of the bracket that does not have a pair ");
			//cout << "\n" << pos;
		}
		
		while (!st.Is_Empty()) {
			vec.push_back(st.Top());
			st.Pop();
		}
		
		cout << "\n Output stream: \n";
		for (size_t i = 0; i < vec.size(); i++) {
			cout <<"\n" <<vec[i]<<"\n";
		}
		//cout << st;
	}

	double calc_stream() {
		Stack<double>locals;
		double a, b;
		for (int i = 0; i<vec.size(); i++) {
			if (vec[i].getType() == Value) {
				locals.Push(atof(vec[i].getStr().c_str()));
			}
			if (vec[i].getType() == Operation) {
				b = locals.Top();
				locals.Pop();
				a = locals.Top();
				locals.Pop();
				char sign = vec[i].getStr()[0];
				switch (sign) {
				
				case '*':
					locals.Push(a * b);

					break;
				case '/':
					locals.Push(a / b);

					break;
				case '+':
					locals.Push(a + b);

					break;
				case '-':
					locals.Push(a - b);

					break;
				}

			}
		}
		double res_d = locals.Top();
		cout << "\n" <<" Result: " << res_d<<endl;
		return res_d;
	}

	//лексический разбиват на лексемы. Синтаксический понимает принадлежит языку или нет ( проверяет что нет ошибок, перевод в обратную польскую)




};
