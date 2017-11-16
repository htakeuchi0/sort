TARGET = Main

CXXFLAGS = -std=c++11

SRCS = $(shell ls *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADS = $(shell ls *.h)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

run: all
	./$(TARGET)

clearn:
	rm -f $(OBJS) $(TARGET)

