CC = gcc
TARGET = market
DTARGET = market_debug
OBJECT = market.c product.o manager.o

$(TARGET) : $(OBJECT)
	$(CC) -o $@ $^

$(DTARGET): $(OBJECT)
	$(CC) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)
