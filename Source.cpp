#include "myList.h"


int main()
{
	MyList::List<int> testList = MyList::CreateList(15);
	//MyList::Insert(testList, 75);
	MyList::Insert(MyList::Insert(testList, 75), 93);

	MyList::Display(testList);

	//printf_s("testList = %d, next = %d, next = %d\n", testList->Data, testList->Next->Data, testList->Next->Next->Data);

	/*MyList::List<int> test2List = MyList::CreateList(63);
	MyList::Insert(test2List, 81);
	printf_s("\ntest2List = %d, next = %d\n", test2List->Data, test2List->Next->Data);
	
	MyList::Insert(testList, test2List);

	printf_s("\ntestList = %d, next = %d, next = %d, next = %d, next = %d\n", testList->Data, testList->Next->Data, testList->Next->Next->Data
		, testList->Next->Next->Next->Data, testList->Next->Next->Next->Next->Data);

	printf_s("\n%d", MyList::Lenght(testList));

	MyList::Delete(testList->Next, testList->Next->Next);
	
	printf_s("\ntestList = %d, next = %d, next = %d\n", testList->Data, testList->Next->Data, testList->Next->Next->Data);

	printf_s("\n%d", MyList::Lenght(testList));*/

	return 0;
}