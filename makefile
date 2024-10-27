CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror

TARGET = redirect

all: $(TARGET)

$(TARGET): redirect.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) redirect.cpp

clean:
	rm -f $(TARGET)
