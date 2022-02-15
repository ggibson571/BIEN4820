CC = g++

gibsong_stats.o: gibsong_stats.cpp gibsong_stats.hpp
	$(CC) -c $^
hist: gibsong_stats_test.cpp gibsong_stats.o
	$(CC) -o $@ $^
gibsong_corr.o: gibsong_corr.cpp gibsong_corr.hpp gibsong_stats.hpp
	$(CC) -c $^
corr: gibsong_corr_test.cpp gibsong_corr.o gibsong_stats.o
	$(CC) -o $@ $^
all: hist corr
clean:
	rm -f *.o
	rm -f hist
	rm -f *.gch
	rm -f *.csv
	
