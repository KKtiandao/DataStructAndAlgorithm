CPP = $(wildcard *.cpp)
HPP  = $(wildcard *.h)
BiList = main.o  bidirectionList.o
Quene = main.o  quene.o
List = main.o  list.o
Stack = main.o  stack.o
Tree = main.o  tree.o
VPATH = dataStruct:dataStruct/array:dataStruct/list:dataStruct/quene : dataStruct/stack:dataStruct/tree
OUTDIR = build
CC = g++
CFLAGS = -v -c -std=gnu++0x
LDFLAGS =
testList:$(List)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)
testBiList:$(BiList)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)

testQuene:$(Quene)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)

testStack:$(Stack)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)
testTree:$(Tree)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)
$(List):%.o:%.cpp
	$(CC) $(CFLAGS) $^
$(BiList):%.o:%.cpp
	$(CC) $(CFLAGS) $^
$(Quene):%.o:%.cpp
	$(CC) $(CFLAGS) $^
$(Stack):%.o:%.cpp
	$(CC) $(CFLAGS) $^
$(Tree):%.o:%.cpp
	$(CC) $(CFLAGS) $^
.PHONY:clean
clean:
	rm -rf test *.o build 
