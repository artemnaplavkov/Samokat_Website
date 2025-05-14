all: courier.o order.o storage.o point.o courier_manager.o order_manager.o storage_manager.o point_manager.o database_manager.o time_manager.o main.o
	g++ courier.o order.o storage.o point.o courier_manager.o order_manager.o storage_manager.o point_manager.o database_manager.o time_manager.o main.o -o out.exe

abstracts:
	g++ -c courier.cpp order.cpp storage.cpp point.cpp
abstract_managers: abstracts
	g++ -c courier_manager.cpp order_manager.cpp storage_manager.cpp point_manager.cpp
database:
	g++ -c database_manager.cpp
time:
	g++ -c time_manager.cpp
main: 
	g++ -c main.cpp