all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/SatirListesiDugum.cpp -o ./lib/SatirListesiDugum.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
bagla:
	g++ ./lib/YoneticiListesi.o ./lib/SatirListesiDugum.o ./lib/SatirListesi.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program