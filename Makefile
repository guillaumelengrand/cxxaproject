CXX=g++
CPPFLAGS=-MMD -I $(INC)
CXXFLAGS=-Werror -Wextra -Wall -std=c++11 -pedantic

OUT=test
LIB=flat_set.so
DIR=src/
SRC= $(addprefix $(DIR), flat_set.cc)
INC=includes/
OBJS=$(SRC:.cc=.o)
DEPS=$(SRC:.cc=.d)

all: $(LIB)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(LIB) : $(SRC)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^

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
