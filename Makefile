CXX=g++
CPPFLAGS=-MMD -I /usr/include/python2.7
CXXFLAGS=-Werror -Wextra -Wall -std=c++11 -pedantic

OUT=test
LIB=$(addprefix $(DIR),flat_set.so)
DIR=src/
SRC= $(addprefix $(DIR), flat_set.cc)
SRCT=tests/test_flat_set.cc
INC=includes/
OBJS=$(SRCT:.cc=.o)
DEPS=$(SRCT:.cc=.d)
TAR=lengra_g-cxxaproject.tar.bz2

all: $(LIB)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(LIB) : $(SRC)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^ -lpython2.7 -lboost_python -lboost_system

check: $(OUT)
	@./test

clean:
	$(RM) $(OUT) $(OBJS) $(DEPS) $(LIB) $(TAR)

distclean: clean
	$(RM) makefile.rules

export: clean
	git archive HEAD --prefix=lengra_g-cxxaproject/ | bzip2 > $(TAR)

.PHONY: clean all distclean check doc
-include $(DEPS)
-include makefile.rules
