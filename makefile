CFLAGS = g++ 

go: main.o Vehicle.o Driver.o Race.o Functions.o Vehicle_Upgrade.o Gameplay.o List.o
	$(CFLAGS) main.o Vehicle.o Driver.o Race.o Functions.o Vehicle_Upgrade.o Gameplay.o List.o -o go

debug: CFLAGS+= -g -ggdb

debug: go
	gdb go

data: go
	valgrind ./go

compile: go
	./go

main.o: main.cpp
	$(CFLAGS) -c main.cpp

Vehicle.o: Vehicle.cpp
	$(CFLAGS) -c Vehicle.cpp

Driver.o: Driver.cpp
	$(CFLAGS) -c Driver.cpp

Race.o: Race.cpp
	$(CFLAGS) -c Race.cpp

Vehicle_Upgrade.o: Vehicle_Upgrade.cpp
	$(CFLAGS) -c Vehicle_Upgrade.cpp

Functions.o: Functions.cpp
	$(CFLAGS) -c Functions.cpp

Gameplay.o: Gameplay.cpp
	$(CFLAGS) -c Gameplay.cpp

List.o: List.cpp
	$(CFLAGS) -c List.cpp

clean:
	rm *.o go
