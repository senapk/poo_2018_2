CPPFLAGS = -std=c++14 -Wall

%:
	g++ $(CPPFLAGS) $@.cpp -o exe_$@
	@ ./exe_$@
clean:
	rm -rf exe_*
md:
	markdown-pp readme.pp.md -o Readme.md
