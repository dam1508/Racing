CFLAGS = g++ 

debug: CFLAGS+= -g

compile: run
	./run

debug: run
	gdb run

run: main.o Vehicle.o
	$(CFLAGS) main.o Vehicle.o -o run

main.o: main.cpp
	$(CFLAGS) -c main.cpp

Vehicle.o: Vehicle.cpp
	$(CFLAGS) -c Vehicle.cpp

clean:
	rm *.o run
