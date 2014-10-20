
CC     = g++

$(shell mkdir -p bin)
$(shell mkdir -p obj)
$(shell mkdir -p lib)


LIBS   = `root-config --cflags --libs --glibs` 
OBJECTS = src/T2bb_bestLimit.C
BINARY  = bin/lim


limit : $(OBJ)
	$(CC) -g $(OBJECTS) $(LIBS) -o $(BINARY)
