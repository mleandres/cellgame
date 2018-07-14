CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD  -lX11 -L/usr/X11/lib -I/usr/X11/include/
EXEC = cellgame
OBJECTS = main.o subject.o cell.o graphicsdisplay.o grid.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
