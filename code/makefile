EXEC = programa

CXX = g++

CXXFLAGS = -Wall -g

OBJS = main.o costs.o editdistance.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

main.o: main.cpp costs.h editdistance.h
	$(CXX) $(CXXFLAGS) -c main.cpp

costs.o: costs.cpp costs.h
	$(CXX) $(CXXFLAGS) -c costs.cpp

editdistance.o: editdistance.cpp editdistance.h costs.h
	$(CXX) $(CXXFLAGS) -c editdistance.cpp

clean:
	rm -f $(OBJS) $(EXEC)