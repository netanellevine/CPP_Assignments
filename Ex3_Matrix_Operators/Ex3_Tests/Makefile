#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion

SOURCE_PATH=sources
OBJECT_PATH=objects
SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

main: Main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -extra-arg=-std=c++2a -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@


clean:
	rm -f *.o demo test main