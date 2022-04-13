hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/ListeFonksiyonlari.o -c ./src/ListeFonksiyonlari.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./bin/test ./lib/DosyaOku.o ./lib/ListeFonksiyonlari.o ./lib/Liste.o ./src/Main.cpp
calistir:
	./bin/test