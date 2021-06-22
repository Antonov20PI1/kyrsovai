/** 
* @file main.cpp
* @brief Главный модуль base64.
*/
#include "Base64.h"
using namespace std;

int main()
{	
	string text, res;
	int ch, rp;
	
	try {
		do{
			cout << "Чтобы закодировать введите 1, декодировать 2, выйти 3" << endl;
			cin >> ch;
			
			switch(ch){
				case 1:{
					cout << "Введите текст для кодирования" << endl;
					cin >> text;
					Base64 a;
					
					cout << "Закодированный текст:" << endl;
					cout << a.encode(text) << endl;
					
					cout << "Вернуться в меню выбора введите 1, чтобы выйти 3" << endl;
					cin >> rp;
					break;
          }case 2:{
					cout << "Введите текст для декодирования" << endl;
					cin >> text;
					Base64 a;
					
					cout << "Декодированный текст:" << endl;
					cout << a.decode(text) << endl;
					
					cout << "Вернуться в меню выбора введите 1, чтобы выйти 3" << endl;
					cin >> rp;
					break;
				}
			}
			
		}while(rp == 1);
		
	}catch (const code_error & e) {
		cerr << "Error: " << e.what() << endl;
	}
	
	
	return 0;
}
