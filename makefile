################################################################################
# MODULE #######################################################################
################################################################################

generic := \
	build/generic/debug.o \
	build/generic/ratio.o \
	build/generic/rectangle.o \
	build/generic/transform.o \
	build/generic/vector.o \

state := \
	build/state/context.o \
	build/state/game.o \
	build/state/machine.o \
	build/state/state.o \
	build/state/title.o

systems := \
	build/system/input.o \
	build/system/physics.o \
	build/system/playerLogic.o \
	build/system/rendering.o \

################################################################################
# TARGET #######################################################################
################################################################################

################################################################################
# TARGET > EXECUTABLE ##########################################################
################################################################################

bin/debug.exe bin/debug.out : \
	$(generic) \
	$(state) \
	$(systems) \
	build/application.o \
	build/main.o  \

################################################################################
# TARGET > CLEAN ###############################################################
################################################################################

.PHONY : clean clean_bins clean_deps clean_doc clean_objs

clean:
ifeq ($(OS),Windows_NT)
	@if exist build rd /s/q build
else
	-@rm -rf build
endif

clean_bins :
ifeq ($(OS),Windows_NT)
	@if exist build echo del /s bin\*.exe
else
	-@rm -rf bin/*.out
endif

clean_deps :
ifeq ($(OS),Windows_NT)
	@if exist build del /s build\*.d
else
	-@rm -rf build/*.d
endif

clean_doc :
ifeq ($(OS),Windows_NT)
	@if exist "doc/html" rd /s/q "doc/html"
else
	-@rm -rf doc/html
endif

clean_objs :
ifeq ($(OS),Windows_NT)
	@if exist build del /s build\*.o
else
	-@rm -rf build/*.o
endif


################################################################################
# TARGET > DOCUMENTATION #######################################################
################################################################################

.PHONY : doc

doc :
	@doxygen doxygen/Doxyfile

################################################################################
# PATTERN RULE #################################################################
################################################################################

bin/%.exe bin/%.out :
	@echo $@
ifeq ($(OS),Windows_NT)
	@if not exist "$(@D)" md "$(@D)"
else
	@mkdir -p $(@D)
endif
	@g++ -Wall -Wextra -L lib -o $@ $^ -l sfml-audio -l sfml-graphics -l sfml-window -l sfml-system

build/%.o : src/%.cpp
	@echo $@
ifeq ($(OS),Windows_NT)
	@if not exist "$(@D)" md "$(@D)"
else
	@mkdir -p $(@D)
endif
	@g++ -c -MMD -I inc -I src -Wall -Wextra -D DEBUG -o $@ $<

################################################################################
# DEPENDENCIES #################################################################
################################################################################

ifeq ($(OS),Windows_NT)
-include $(shell if exist build dir /s/b build\*.d)
else
-include $(shell find build -name *.d)
endif
