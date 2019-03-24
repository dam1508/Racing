CFLAGS = g++ 

debug: CFLAGS+= -g

compile: go
	./go

debug: go
	gdb go

go: main.o Vehicle.o Driver.o Race.o Functions.o Vehicle_Upgrade.o Gameplay.o
	$(CFLAGS) main.o Vehicle.o Driver.o Race.o Functions.o Vehicle_Upgrade.o Gameplay.o -o go

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

clean:
	rm *.o go
