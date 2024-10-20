CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = src/main.cpp src/car.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = carrera


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
