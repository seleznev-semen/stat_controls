#pragma once

enum class LexemeType
{
   SCALAR = 0,		// Скаляр
   ELEMENT,			// Элемент
   ARITHMETIC,		// Арифметическая операция ( + - * / )
   BOOLEAN,			// Булев оператор				( AND OR )
   LOGIC,			// Логический оператор		( = != > >= < <= )
   FUNCTION,		// Функция
   SUM            // Сумма
   /* TODO Пока реализую только основные типы лексем
   PERIOD,			// Условие периода			( &NP )
   LIST,				//	Список
   IN,				   // in
   INT,				// int для convert
   NUMERIC,			// numeric для convert
   CONDITION,		// Условие
   SUM
   */
};



