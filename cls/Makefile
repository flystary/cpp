main: main.o string_u.o ipv4_u.o int_u.o
		g++ -std=c++11 -o cls -lpcrecpp -ljsoncpp -luuid main.o string_u.o ipv4_u.o int_u.o 
		rm -f *.o
main.o: main.cpp string_u.h
		g++ -std=c++11 -c main.cpp 
string_u.o: string_u.cpp string_u.h
		g++ -std=c++11 -c string_u.cpp 
ipv4_u.o: ipv4_u.cpp ipv4_u.h
		g++ -std=c++11 -c ipv4_u.cpp 
int_u.o: int_u.cpp int_u.h
		g++ -std=c++11 -c int_u.cpp 

clean:
		rm -f cls
