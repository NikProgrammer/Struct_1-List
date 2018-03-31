#pragma once

#include <stdlib.h>
#include <stdio.h>
namespace MyList {
	
	//Определение структуры
	template <typename T>
	struct _MyList
	{
		T Data;

		struct _MyList *Next;
		struct _MyList *Previous;
	};
	
	//Определение указателя на структуру
	template <typename T>
	using List = struct _MyList<T>*;
	
	enum class Placement {Front, Back};

	template <typename T>
	List<T> Add(List<T> Object, const T & Value, Placement Place = Placement::Back)
	{
		return Add(Object, CreateList(Value), Place);
	}

	template <typename T>
	List<T> Add(List<T> LObject, List<T> RObject, Placement Place = Placement::Back)
	{
		return (Place == Placement::Back) ? Insert(GetTail(LObject), RObject) : Insert(GetTail(RObject), LObject);
	}

	//Функция создания элемента структуры
	template <typename T>
	List<T> CreateList(const T & Value)
	{
		List<T> Object = (List<T>)malloc(sizeof(struct _MyList<T>));
		Object->Data = Value;
		Object->Next = nullptr;
		Object->Previous = nullptr;

		return Object;
	}

	//Проверка на корневой элемент
	template <typename T>
	bool IsRoot(const List<T> Object)
	{
		return(Object->Previous) ? false : true;
	}

	//Проверка на последний элемент
	template <typename T>
	bool IsTail(const List<T> Object)
	{
		return(Object->Next) ? false : true;
	}

	//Возвращает корневой элемент
	template <typename T>
	List<T> GetRoot(List<T> Object)
	{
		while (!IsRoot(Object))
		{
			Object = Object->Previous;
		}

		return Object;
	}

	//Возвращает последний элемент
	template <typename T>
	List<T> GetTail(List<T> Object)
	{
		while (!IsTail(Object))
		{
			Object = Object->Next;
		}

		return Object;
	}

	template <typename T>
	void Destroy(List<T> Object)
	{
		if (Object == nullptr)
			return;

		free(Object);
	}
	//вставка цепочки/элемента
	template <typename T>
	List<T> Insert(List<T> Object, List<T> NewObject)
	{
		List<int> Root = GetRoot(NewObject);
		List<int> Tail = GetTail(NewObject);

		Root->Previous = Object;
		
		if (Object->Next)
		{
			Tail->Next = Object->Next;
			Object->Next->Previous = Tail;
		}
		
		Object->Next = Root;

		return NewObject;
	}
	//вставка цепочки/элемента
	template <typename T>
	List<T> Insert(List<T> Object, const T & Value)
	{
		return Insert(Object, CreateList(Value));
	}
	//удаление элемента
	template <typename T>
	void Delete(List<T> Object)
	{
		Object->Previous->Next = Object->Next;
		Object->Next->Previous = Object->Previous;

		free(Object);

	}
	//удаление цепочки
	template <typename T>
	void Delete(List<T> RObject, List<T> TObject)
	{
		RObject->Previous->Next = TObject->Next;
		TObject->Next->Previous = RObject->Previous;

		free(RObject);
		free(TObject);

	}

	//возвращает длину списка
	template <typename T>
	int Lenght(List<T> list)
	{
		int lenght = 0;
		if (list == nullptr)
		{
			return lenght;
		}

		List<int> Root = GetRoot(list);
		lenght++;
		while (!IsTail(Root))
		{
			Root = Root->Next;
			lenght++;
		}

		return lenght;
	}
	//вывод на печать
	template <typename T>
	int Display(List<T> list)
	{
		if (list == nullptr)
		{
			return -1;
		}

		if (Lenght(list) == 1)
		{
			printf_s("%d ", list->Data);
			return 0;
		}

		while (true)
		{
			printf_s("%d ", list->Data);
			list = list->Next;
			if (IsTail(list))
			{
				printf_s("%d ", list->Data);
				return 0;
			}
		}
	}
}
