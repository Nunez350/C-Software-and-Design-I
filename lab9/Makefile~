all:	lab9

lab9:	main-2.o drawRect.o drawX.o drawPixel.o
	g++ main-2.o drawRect.o drawX.o drawPixel.o -o lab9
main-2.o: main-2.C
	g++ -Wall -c main-2.C

drawRect.o: drawRect.C
	g++ -o drawRect.o -c drawRect.C

drawX.o:	drawX.C
	g++ -o drawX.o -c drawX.C

drawPix.o:	drawPix.C
	g++ -o drawPixel.o -c drawPixel.C

clean:	
	rm lab9


