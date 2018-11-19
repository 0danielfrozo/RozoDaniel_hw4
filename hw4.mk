archivo: Resultados_hw4.pdf
	 xdg-open Resultados_hw4.pdf 
Resultados_hw4.pdf: Resultados_hw4.tex 45grados.jpg grados.jpg cond_1.jpg cond_2.jpg cond_3.jpg promedio_1.jpg promedio_2.jpg promedio_3.jpg
	pdflatex Resultados_hw4.tex
	rm *.log
	rm *.aux
	clear
45grados.jpg grados.jpg cond_1.jpg cond_2.jpg cond_3.jpg promedio_1.jpg promedio_2.jpg promedio_3.jpg: Plots_hw4.py 45grados.txt grados.txt con_1.txt con_3.txt con_2.txt prom_1.txt prom_2.txt prom_3.txt 
	python Plots_hw4.py 45grados.txt grados.txt con_1.txt con_3.txt con_2.txt prom_1.txt prom_2.txt prom_3.txt 
45grados.txt grados.txt: ode.cpp
	g++ ode.cpp
	./a.out
con_1.txt con_3.txt con_2.txt prom_1.txt prom_2.txt prom_3.txt: PDE.cpp
	g++ PDE.cpp
	./a.out
clean:
	rm *.jpg
	rm *.txt
	rm *.pdf
	rm a.out
	




