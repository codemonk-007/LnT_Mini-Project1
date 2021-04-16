PROJ_NAME = udhaar

ifdef OS
	RM = del
	FixPath = $(subst /,\,$1)
	EXEC = exe
else 
	ifeq ($(shell uname),Linux)
		RM = rm -rf
		FixPath = $1
			EXEC = out
	endif
endif

.PHONY: run clean test doc all

all:
	gcc -I inc inc/udhaar.h src/udhaar.c project_main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run:
	$(call FixPath,$(PROJ_NAME).$(EXEC))

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem -I inc inc/udhaar.h src/udhaar.c project_main.c

valgrind:
	valgrind ./$(PROJ_NAME).$(EXEC)

clean:
	$(RM) *.out

