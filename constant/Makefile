
SRCS_CPP_FILE = constExpression.cpp
TARGET = constTest


CXX = g++
# CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address
LIBS = -lpthread


ifeq ($(RELEASE), 1)
OBJS_DIR = Release
DBG_FLAGS = -O2 -DNDEBUG
else
OBJS_DIR = Debug
DBG_FLAGS = -O0 -DDEBUG
endif
DEPEND_FILE = $(OBJS_DIR)/depend_file

# OBJS = $(SRCS_C_FILE:%.c=%.o)
OBJS += $(SRCS_CPP_FILE:%.cpp=${OBJS_DIR}/%.o)
SRCS = $(SRCS_C_FILE) $(SRCS_CPP_FILE)
# $(info OBJS is ${OBJS})

RM = rm
MKDIR = mkdir -p

all : $(TARGET)

run: clean all
	clear
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ ${LIBS}
	# $(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LBLIBS)

$(OBJS_DIR)/%.o: %.cpp
	# $(info input:$^  output:$@  justname:$* )
	@`[ -d $(OBJS_DIR) ] || $(MKDIR) $(OBJS_DIR)`
	@echo "=========================================="
	@echo "= compiling $@ "
	@echo "=========================================="
	$(CXX) -c $< -o $@ ${CXXFLAGS} $(DBG_FLAGS)

depend :
	@`[ -d $(OBJS_DIR) ] || $(MKDIR) $(OBJS_DIR)`
	@$(RM) -f $(DEPEND_FILE)
	@for FILE in $(SRCS:%.cpp=%); df  co \
		$(CXX) -MM -MT $(OBJS_DIR)/$$FILE.o $$FILE.cpp >> $(DEPEND_FILE); \
	done
	# $(CXX) -MM $(SRCS) > $(DEPEND_FILE)
	#gccmakedep $(SRCS)

clean:
	$(RM) -rf $(OBJS_DIR)/*
	$(RM) -rf $(TARGET) $(DEPEND_FILE)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), depend)
ifneq ($(SRCS),)
-include $(DEPEND_FILE)
endif
endif
endif


