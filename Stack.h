#pragma once

#include <stdlib.h>
#include <stdio.h>

namespace MyStack
{
	template <typename T>
	struct _MyStack
	{
		T Value;

		struct _MyStack<T> *Next;
	};

	template <typename T>
	using Stack = struct _MyStack<T> *;

	//Создание элемента стэка
	template <typename T>
	Stack<T> CreateStack(const T & Value)
	{
		Stack<T> NewObject = (Stack<T>)malloc(sizeof(struct _MyStack<T>));
		NewObject->Value = Value;
		NewObject->Next = nullptr;

		return NewObject;
	}

	template <typename T>
	void Push(Stack<T> Object, const T & Value)
	{
		Stack<T> NewObject = CreateStack(Value);
		NewObject->Next = Object;
		Object = NewObject;
	}

	template <typename T>
	bool IsEmpty(Stack<T> Object)
	{
		return(Object == nullptr) ? true : false;
	}

	template <typename T>
	T Pop(Stack<T> Object)
	{
		T topValue;
		Stack<T> tempObject;
		tempObject = Object;
		topValue = Object->Value;
		Object = Object->Next;
		free(tempObject);

		return topValue;
	}

	template <typename T>
	void DisplayStack(Stack<T> Object)
	{
		while (!IsEmpty(Object))
		{
			printf_s("%d ", Pop(Object));
		}
	}
	
	
}
