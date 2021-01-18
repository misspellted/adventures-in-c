
# Do a clean build for the default action
all: clean build

# clean and build are targets that do not result in a file being created.
.PHONY: clean build

# Delete files, using the tool specified by the implementation's RM variable.
clean:
	$(RM) program

# Create the artifact of the project, using the default C compiler macro.
build:
	$(CC) program.c -o program
