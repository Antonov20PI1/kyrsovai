/**
 * @file Base64.cpp
 */
#include "Base64.h"
/**
* @brief Кодирование
* @param message - кодируемый текст. Не должен быть пустой строкой 
* или содержать символы не принадлежащие ASCII.
* @throw code_error, если произошла ошибка.
* @return Закодированная строка
*/
std::string Base64::encode(string message)
{
	// Проверка на ошибки
	if(message == "")
		throw code_error("Введена пустая строка!");
	for(auto a : message)
		if(a < 0 || a > 127)
			throw code_error("Введены недопустимые символы!");
	
	string text, tmp, result;
	int number;
	
	for(int i = 0; i < message.length(); i++)
		text += bin(message[i]);
	
	if(message.length() % 3 == 2)
		text.append("00");
	else if(message.length() % 3 == 1)
		text.append("0000");
	
	while(!text.empty()){
		for(int i = 0; i < 6; i++)
			tmp += text[i];
		
		text.erase(0, 6);
		
		result += alph[dec(tmp)];
		tmp = "";
	}
	
	if(message.length() % 3 == 2)
		result.append("=");
	else if(message.length() % 3 == 1)
		result.append("==");
	
	return result;
}
/**
* @brief Декодирование
* @param message - декодируемый текст. Не должен быть пустой строкой
* или содержать символы не принадлежащие алфавиту base64, 
* также символы "=" допускаются только в конце и не более двух.
* @throw code_error, если произошла ошибка.
* @return Декодированная строка
*/
std::string Base64::decode(string message)
{	
	if(message == "")
		throw code_error("Введена пустая строка!");
	for(auto a : message)
		if(alph.find(a) == -1 && a != '=')
			throw code_error("Введены недопустимые символы!");
	
	string text, tmp, result;
	int count = 0;
	
	for(auto a : message){
		if(a == '=')
			count++;
	}
	
	if(count == 2){
		message.erase(message.length() - 2, 2);
	}else if(count == 1){
		message.erase(message.length() - 1, 1);
	}
	
	if(message.find("=") != -1)
		throw code_error("Текст введён не корректно!");
	
	for(int i = 0; i < message.length(); i++){
		text += bin(alph.find(message[i]), true);
	}
	
	if(count == 2){
		text.erase(text.length() - 4, 4);
	}else if(count == 1){
		text.erase(text.length() - 2, 2);
	}
	
	while(!text.empty()){
		for(int i = 0; i < 8; i++)
			tmp += text[i];
		
		text.erase(0, 8);
		
		result += (char)dec(tmp);
		tmp = "";
	}
	
	return result;
}
/**
* @brief Перевод из десятичной СС в двоичную СС.
* @param num - число типа int для перевода в двоичную СС.
* @param lenSix - при значении true дополняет не значащие нули до 6ти бит, 
* при значении false дополняет незначащие нули до 8ми бит.
* @return Двоичный код числа в виде строки из 6ти или 8ми символов.
*/
std::string Base64::bin(int num, bool lenSix)
{
	string bin, tmp;

    while (num){
		bin += to_string(num % 2);
		num /= 2;
    }
	
	if(lenSix){
		if(bin.length() < 6)
			for(int i = bin.length(); i < 6; i++)
				bin += "0";
	}else{
		if(bin.length() < 8)
			for(int i = bin.length(); i < 8; i++)
				bin += "0";
	}
	
	for(int i = 0; i < bin.length(); i++)
		tmp += bin[bin.length() - i - 1];
	
    return tmp;
}
/**
* @brief Перевод из двоичной СС в десятичную СС.
* @param bin - строка типа string для перевода в десятичную СС.
* @return Десятичное число типа int
*/
int Base64::dec(string bin)
{	
	int dec = 0;
	
	for(int i = 0; i < bin.length(); i++) {
		if(bin[bin.length() - i - 1] == '1')
			dec += pow(2, i);
	}		
    return dec;
}
