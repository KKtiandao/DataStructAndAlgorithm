SUBOBJS = $(patsubst %.cpp,%.o,$(shell ls *.cpp))
OBJS += $(SUBOBJS)
$(SUBOBJS):%.o:%.cpp
	test -d $(OUTDIR) || mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/$@
.PHONY:clean
clean:
	rm -rf *.o 
