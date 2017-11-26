TARGET = Sample

CXXFLAGS = -Wall -std=c++11

SRCS = $(shell ls *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADS = $(shell ls *.h)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

