update:
	git pull --rebase

detof: detof.cxx
	g++ -std=c++0x -o detof detof.cxx
