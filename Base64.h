/** 
* @file Base64.h
* @author И.С.Антонов
* @version 1.0
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля Base64
*/
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
/** @brief Кодирование и декодирование base64
* @details Создаётся объект класса, а с помощью методов encode и decode 
* осуществляется кодирование и декодирование
* @warning Реализация только для латинских символов
*/
class Base64
{
private:
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
public:
	string bin(int num, bool lenSix = false);
	int dec(string bin);
	string encode(string message);
	string decode(string message);
};
/** @brief Класс обработки ошибок code_error
* @details Используется для вывода сообщений об ошибках
*/
class code_error: public std::invalid_argument
{
public:
	explicit code_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit code_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
