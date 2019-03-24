CFLAGS = g++ 

debug: CFLAGS+= -g

compile: go
	./go

debug: go
	gdb go

go: main.o Vehicle.o Driver.o Race.o Functions.o
	$(CFLAGS) main.o Vehicle.o Driver.o Race.o Functions.o -o go

main.o: main.cpp
	$(CFLAGS) -c main.cpp

Vehicle.o: Vehicle.cpp
	$(CFLAGS) -c Vehicle.cpp

Driver.o: Driver.cpp
	$(CFLAGS) -c Driver.cpp

Race.o: Race.cpp
	$(CFLAGS) -c Race.cpp

Functions.o: Functions.cpp
	$(CFLAGS) -c Functions.cpp

clean:
	rm *.o go
