#pragma once

#include <cstdlib>

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
		using List = struct _LISTITEM<T> *;

		enum class Placement { Front, Back };

		template <typename T>
		List<T> Add(List<T> Object, const T & Value, Placement Place = Placement::Back)
		{

		}
		//возвращает корневой элемент
		template <typename T>
		List<T> GetRoot(List<T> Object)
		{
			while (!IsRoot(Object))
			{
				Object = Object->Previous;
			}
			return Object;
		}
		//возвращает последний элемент
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
		List<T> Insert(List<T> Object, const T & Value)
		{
			Object->Value = Value;
			return Object;
		}

		template <typename T>
		List<T> Insert(List<T> LObject, List<T> RObject);
		//создает элемент списка
		template <typename T>
		List<T> Create(const T & Value)
		{
			List<T> Object = (List<T>)malloc(sizeof(struct _LISTITEM));
			Object->Value = Value;
			Object->Previous = nullptr;
			Object->Next = nullptr;

			return Object;
		}
		//уничтожает элемент списка
		template <typename T>
		void Destroy(List<T> Object)
		{
			if (Object == nullptr)
				return;

			free(Object);
		}

		template <typename T>
		bool IsRoot(List<T> Object)
		{
			return (Item->Previous) ? false : true;
		}

		template <typename T>
		bool IsTail(List<T> Object)
		{
			return (Item->Next) ? false : true;
		}
	}
}