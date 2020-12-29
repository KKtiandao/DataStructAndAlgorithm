CPP = $(wildcard *.cpp)
OBJS = main.o array.o
DIR = dataStruct/array
OUTDIR = build
CC = gcc
CFLAGS = -c
LDFLAGS = -lstdc++
test:$(OBJS)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) -o  $(OUTDIR)/$@ $^ $(LDFLAGS)
$(OBJS):$(CPP) $(DIR)/array.cpp
	$(CC) $(CFLAGS) $^
.PHONY:clean
clean:
	rm -rf test *.o build 
