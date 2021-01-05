#include "dataStruct/array/array.h"
#include "dataStruct/list/bidirectionList.h"
#include "dataStruct/quene/quene.h"
#include "dataStruct/stack/stack.h"

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

void TestQuene() 
{
    auto l = new Quene<char>();
	std::cout<< "size:"<< l->Size() <<std::endl;
	l->Push('0');
	l->Push('1');
	l->Push('2');
	l->Push('3');
	l->Push('4');
	l->Push('5');
	l->Push('6');
	l->Push('6');
	l->Push('7');
	l->Push('8');
	l->Push('9');
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	l->Dump();
	delete l->Pop();
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	l->Dump();
	delete l->Pop();
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	delete l->Pop();
	l->Dump();
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	delete l;
	
}

void TestStack() 
{
    auto l = new Stack<char>();
	std::cout<< "size:"<< l->Size() <<std::endl;
	l->Push('0');
	l->Push('1');
	l->Push('2');
	l->Push('3');
	l->Push('4');
	l->Push('5');
	l->Push('6');
	l->Push('6');
	l->Push('7');
	l->Push('8');
	l->Push('9');
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	l->Dump();
	delete l->Pop();
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	l->Dump();
	auto p = l->Pop();
	p->Print();
	delete p;
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	delete l->Pop();
	l->Dump();
	std::cout<< "*****************" <<"size:"<< l->Size() << "****************" <<std::endl;
	delete l;
	
}
int main (int argCounts, char* args[]) {
//	testArray();
//	TestList();	
//  TestQuene();	
	TestStack();	
	return 0;
}

