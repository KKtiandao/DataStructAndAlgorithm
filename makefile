export OBJS = $(patsubst %.cpp,%.o,$(shell ls *.cpp))
SUBDIRS = dataStruct

#VPATH = dataStruct:dataStruct/list
TARGETS = array list # bidirectionList
MAKE = make
export OUTDIR = $(shell pwd)/build
export CC = g++
export CFLAGS = -v -c -std=gnu++0x
export LDFLAGS =
all:$(TARGETS) 
$(TARGETS): $(SUBDIRS) $(OBJS)
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(MAKE) -C $(SUBDIRS) -w
	$(CC) -o  $(OUTDIR)/$@ $(OUTDIR)/*.o $(LDFLAGS)
$(OBJS):%.o:%.cpp
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/$@
$(SUBDIRS):
	$(MAKE) -C $^ -w
.PHONY:clean
clean:
	rm -rf build
