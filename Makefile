CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Customer.o Analytical.o Simulation.o PriorityQ.o

main : ${OBJS}
		${CXX} ${CXXFLAGS} -o $@ ${OBJS}

clean :
		rm ${OBJS} main
