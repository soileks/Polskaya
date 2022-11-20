#include <string>
#include <iostream>
#include <stack> // сделать свой
#include <queue> // сделать свой
//вместо switch можно сделать список(массив) правил
//базовый класс rool, три метода: перейти, чек и действие
//сделать отдельными классами лексический, синтаксический анализы и транслятор
#include<map>

using namespace std;





	/*void add_Mem()
	{
		int* pp = new int[size * 2];
		end = 0; //nepravilno(ne ravno 0)
		for (size_t i = 1; i < size; i++)
		{
			pp[i] = p[next(end)];
			end = next(end);
		}
		delete[] p;
		p = pp;
		size *= 2;
	}*/













int  main() {
	//string str = "(123 -10)/ 50 *	\t	30 \n";
	//cout << str;
	//queue <Lexema> lex_res;
	//lex_res = lex(str);//вызываем лексический анализатор
	//print(lex_res);
	//void func();
	/*string input = "140+12";
	polsk p(input);
	p.func();*/
	
	return 0;
}









//Queue<Lexema*>* que(string input) {
//	input += ' ';
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
//				res->Push(new Lexema(tmp, Operation));//помещаем в очередь, которая используется как выходной поток
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
//				res->Push(new Lexema(tmp, Value));   // tak peredelay vse
//				tmp = c;
//				Lexema l2(tmp, Operation);//операцию кладем в очередь
//				res->Push(new Lexema(tmp, Operation));
//				state = 0;
//				break;
//			}
//			fres = sep.find(c);//проверяем на то, что встретили разделитель
//			if (fres >= 0) {
//				Lexema l(tmp, Value);//число помещаем в очередь
//				res->Push(new Lexema(tmp, Value));
//				state = 0;
//				break;
//			}
//			break;
//		}
//	}
//	return res;
//}
//
//
//};