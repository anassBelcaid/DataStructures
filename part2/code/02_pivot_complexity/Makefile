COMPILER=g++
flags= -o 3 -std=c++17
binary= simulate


results.csv: simulation.cpp
	$(COMPILER) $(flags) -o $(binary) simulation.cpp
	./$(binary)


graphics_linear: results.csv generate_plots.py
	python ./generate_plots.py 

graphics_logarithmic: results.csv generate_plots.py
	python ./generate_plots.py  -l 1
