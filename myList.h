#pragma once

#include <stdlib.h>
#include <stdio.h>
namespace MyList {
	
	//����������� ���������
	template <typename T>
	struct _MyList
	{
		T Data;

		struct _MyList *Next;
		struct _MyList *Previous;
	};
	
	//����������� ��������� �� ���������
	template <typename T>
	using List = struct _MyList<T>*;
	
	//������� �������� �������� ���������
	template <typename T>
	List<T> CreateList(const T & Value)
	{
		List<T> Object = (List<T>)malloc(sizeof(struct _MyList<T>));
		Object->Data = Value;
		Object->Next = nullptr;
		Object->Previous = nullptr;

		return Object;
	}

	//�������� �� �������� �������
	template <typename T>
	bool IsRoot(const List<T> Object)
	{
		return(Object->Previous) ? false : true;
	}

	//�������� �� ��������� �������
	template <typename T>
	bool IsTail(const List<T> Object)
	{
		return(Object->Next) ? false : true;
	}

	//���������� �������� �������
	template <typename T>
	List<T> GetRoot(List<T> Object)
	{
		while (!IsRoot(Object))
		{
			Object = Object->Previous;
		}

		return Object;
	}

	//���������� ��������� �������
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
	//������� �������/��������
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
	//������� �������/��������
	template <typename T>
	List<T> Insert(List<T> Object, const T & Value)
	{
		return Insert(Object, CreateList(Value));
	}
	//�������� ��������
	template <typename T>
	void Delete(List<T> Object)
	{
		Object->Previous->Next = Object->Next;
		Object->Next->Previous = Object->Previous;

		free(Object);

	}
	//�������� �������
	template <typename T>
	void Delete(List<T> RObject, List<T> TObject)
	{
		RObject->Previous->Next = TObject->Next;
		TObject->Next->Previous = RObject->Previous;

		free(RObject);
		free(TObject);

	}

	//���������� ����� ������
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
