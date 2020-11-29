
CC=g++
CXXFLAGS=`pkg-config --cflags --libs dali2-core dali2-adaptor dali2-adaptor-integration dali2-toolkit`

all: app

app: source.cpp
	$(CC) -g -O0 source.cpp -o  app -std=c++17 $(CXXFLAGS)
clean:
	rm app
