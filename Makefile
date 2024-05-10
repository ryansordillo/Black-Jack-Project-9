# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/CS102/project-9-final-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CS102/project-9-final-project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/cmake/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/cmake/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /workspaces/CS102/project-9-final-project/CMakeFiles /workspaces/CS102/project-9-final-project//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /workspaces/CS102/project-9-final-project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named black_jack

# Build rule for target.
black_jack: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 black_jack
.PHONY : black_jack

# fast build rule for target.
black_jack/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/build
.PHONY : black_jack/fast

black_jack.o: black_jack.cpp.o
.PHONY : black_jack.o

# target to build an object file
black_jack.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/black_jack.cpp.o
.PHONY : black_jack.cpp.o

black_jack.i: black_jack.cpp.i
.PHONY : black_jack.i

# target to preprocess a source file
black_jack.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/black_jack.cpp.i
.PHONY : black_jack.cpp.i

black_jack.s: black_jack.cpp.s
.PHONY : black_jack.s

# target to generate assembly for a file
black_jack.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/black_jack.cpp.s
.PHONY : black_jack.cpp.s

stack.o: stack.cc.o
.PHONY : stack.o

# target to build an object file
stack.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/stack.cc.o
.PHONY : stack.cc.o

stack.i: stack.cc.i
.PHONY : stack.i

# target to preprocess a source file
stack.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/stack.cc.i
.PHONY : stack.cc.i

stack.s: stack.cc.s
.PHONY : stack.s

# target to generate assembly for a file
stack.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_jack.dir/build.make CMakeFiles/black_jack.dir/stack.cc.s
.PHONY : stack.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... black_jack"
	@echo "... black_jack.o"
	@echo "... black_jack.i"
	@echo "... black_jack.s"
	@echo "... stack.o"
	@echo "... stack.i"
	@echo "... stack.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

