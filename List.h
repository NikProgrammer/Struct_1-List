#pragma once
#include <cstdlib>
#include <stdio.h>

namespace ITStep
{
	namespace List
	{
		template <typename T>
		struct _LISTITEM
		{
			T Value;

			struct _LISTITEM<T> *Next;
			struct _LISTITEM<T> *Previous;
		};

		template <typename T>
		using LISTITEM = struct _LISTITEM<T>;

		template <typename T>
		using List = LISTITEM<T> *;

		enum class Placement { Front, Back };

		template <typename T>
		List<T> Add(List<T> Object, const T & Value, const Placement Place = Placement::Back)
		{
			return Add(Object, Create(Value), Place);
		}

		template <typename T>
		List<T> Add(List<T> LObject, List<T> RObject, const Placement Place = Placement::Back)
		{
			return (Place == Placement::Back) ? Insert(GetTail(LObject), RObject) : Insert(GetTail(RObject), LObject);
		}

		template <typename T>
		List<T> Create(const T & Value)
		{
			List<T> Object = (List<T>)malloc(sizeof(struct _LISTITEM<T>));
			Object->Previous = nullptr;
			Object->Next = nullptr;
			Object->Value = Value;

			return Object;
		}

		template <typename T>
		List<T> Delete(List<T> Object)
		{
			return nullptr; /* Возвращает указатель на предыдущий элемент. Если его нет - на послед. Если его нет - nullptr */
		}

		template <typename T>
		void Destroy(List<T> Object)
		{
			if (Object == nullptr)
				return;

			free(Object);
		}

		template <typename T>
		List<T> GetRoot(List<T> Object)
		{
			while (!IsRoot(Object))
				Object = Object->Previous;

			return Object;
		}

		template <typename T>
		List<T> GetTail(List<T> Object)
		{
			while (!IsTail(Object))
				Object = Object->Next;

			return Object;
		}

		template <typename T>
		List<T> Insert(List<T> Object, const T & Value)
		{
			return Insert(Object, Create(Value));
		}

		template <typename T>
		List<T> Insert(List<T> LObject, List<T> RObject)
		{
			List<T> RRoot = GetRoot(RObject);
			List<T> RTail = GetTail(RObject);

			RTail->Next = LObject->Next;
			if (LObject->Next)
				LObject->Next->Previous = RTail;
			RRoot->Previous = LObject;
			LObject->Next = RRoot;

			return RRoot;
		}

		template <typename T>
		bool IsRoot(const List<T> Object)
		{
			return (Object->Previous) ? false : true;
		}

		template <typename T>
		bool IsTail(const List<T> Object)
		{
			return (Object->Next) ? false : true;
		}
	}
}