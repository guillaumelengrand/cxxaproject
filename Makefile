CXX=g++
CPPFLAGS=-MMD -I /usr/include/python2.7
CXXFLAGS=-Werror -Wextra -Wall -std=c++11 -pedantic

OUT=test
LIB=$(addprefix $(DIR),flat_set.so)
DIR=src/
SRC= $(addprefix $(DIR), flat_set.cc)
SRCT=tests/test_insert.cc
INC=includes/
OBJS=$(SRCT:.cc=.o)
DEPS=$(SRCT:.cc=.d)

all: $(LIB)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(LIB) : $(SRC)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^ -lpython2.7 -lboost_python -lboost_system

check: $(OUT)

#doc:
#	doxygen Doxyfile

clean:
	$(RM) $(OUT) $(OBJS) $(DEPS) $(LIB)
#	$(RM) -r doc/html doc/latex

distclean: clean
	$(RM) makefile.rules

.PHONY: clean all distclean check doc
-include $(DEPS)
-include makefile.rules
