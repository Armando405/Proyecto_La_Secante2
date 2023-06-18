# Mi asombroso Makefile

# (Objetivo) : (dependecias)
# 	(comando 1)
# 	(comando 2)

bin/proyecto.exe : src/main.cpp include/calculadora.hpp include/Secante.hpp
	@echo Compilando codigo fuente.....
	g++ -o bin/proyecto src/main.cpp -Iinclude

run : bin/proyecto.exe
	./bin/proyecto.exe
clean : bin/proyecto.exe
		rm -f./bin/*.exe