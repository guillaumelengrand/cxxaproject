CXX=g++
CPPFLAGS=-MMD -I /usr/include/python2.7
CXXFLAGS=-Werror -Wextra -Wall -std=c++11 -pedantic

OUT=test
OUT2=test_bench
LIB=$(addprefix $(DIR),flat_set.so)
DIR=src/
SRC= $(addprefix $(DIR), flat_set.cc)
SRCT=tests/test_flat_set.cc
BEN=tests/test_bench.cc
INC=includes/
OBJS=$(SRCT:.cc=.o)
OBJ=$(BEN:.cc=.o)
DEPS=$(SRCT:.cc=.d)
DEP=$(BEN:.cc=.d)
TAR=lengra_g-cxxaproject.tar.bz2

all: $(LIB)
	python src/flat_set.py

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
$(OUT2): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(LIB) : $(SRC)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^ -lpython2.7 -lboost_python -lboost_system

check: $(OUT)
	@./test

bench: $(LIB) $(OUT2)
	@echo "\033[1;32mBench C++: \033[0m"
	@./test_bench
	@echo "\n"
	@echo "\033[1;32mBench Pyhon: \033[0m"
	@python src/flat_set.py bench

clean:
	$(RM) $(OUT) $(OBJS) $(DEPS) $(LIB) $(TAR) $(OUT2) $(OBJ) $(DEP)

export: clean
	git archive HEAD --prefix=lengra_g-cxxaproject/ | bzip2 > $(TAR)

.PHONY: clean all check doc bench
-include $(DEPS)
