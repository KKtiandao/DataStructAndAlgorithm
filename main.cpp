#include "dataStruct/array/array.h"
#include "dataStruct/list/bidirectionList.h"

void TestList(); 

int main (int argCounts, char* args[]) {
	testArray();
//	TestList();	
	return 0;
}

void TestList() 
{
    auto l = new BiList<char>();
	std::cout<< "size:"<< l->Size() <<std::endl;
	l->PushBack('0');
	l->PushBack('1');
	l->PushBack('2');
	l->PushBack('3');
	l->PushBack('4');
	l->PushBack('5');
	l->PushBack('6');
	l->PushFront('6');
	l->PushFront('7');
	l->PushFront('8');
	l->PushFront('9');
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	l->Dump();
	l->PopFront();
	l->DumpFromBack();
	delete l->PopBack();
	delete l->PopBack();
	l->Dump();
	delete l;
}
