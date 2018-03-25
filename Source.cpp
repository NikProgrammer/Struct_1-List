#include "List.h"


int main()
{

	

	ITStep::List::List<int> Object = ITStep::List::Create(10);
	ITStep::List::Insert(Object, 20);
	ITStep::List::List<int> Object1 = Object->Next;

	printf_s("%d\n", ITStep::List::Insert(Object, 20)->Value);
	printf_s("%d\n", Object->Next->Previous->Value);
	printf_s("%d\n", Object1->Value);
	//printf_s("%d\n", ITStep::List::Add(ITStep::List::GetTail(Object), 80)->Value);

	return 0;
}