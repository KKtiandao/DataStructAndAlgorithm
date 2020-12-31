CPP = $(wildcard *.cpp)
HPP  = $(wildcard *.h)
BiList = main.o  bidirectionList.o
List = main.o  list.o
DIR = dataStruct/list
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
$(List):$(CPP) $(DIR)/list.h $(DIR)/list.cpp
	$(CC) $(CFLAGS) $^
$(BiList):$(CPP) $(DIR)/bidirectionList.h $(DIR)/bidirectionList.cpp
	$(CC) $(CFLAGS) $^
.PHONY:clean
clean:
	rm -rf test *.o build 
