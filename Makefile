CC = gcc
TARGET = shop
DTARGET = shop_debug
OBJECTS = main.c product.o manager.o
CFLAGS = -W -Wall

clean :
	rm *.o $(TARGET) $(DTARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
