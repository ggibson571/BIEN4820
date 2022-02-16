CC = g++

gibsong_vector_ops.o: gibsong_vector_ops.cpp gibsong_vector_ops.hpp
	$(CC) -c $^
#vect: gibsong_vector_ops.cpp gibsong_vector_ops.o
#$(CC) -o $@ $^
gibsong_stats.o: /home/gibsong/BIEN4820/Lab1/gibsong_stats.cpp /home/gibsong/BIEN4820/Lab1/gibsong_stats.hpp
	$(CC) -c $^
stats: /home/gibsong/BIEN4820/Lab1/gibsong_stats_test.cpp gibsong_stats.o
	$(CC) -o $@ $^
prep: gibsong_pre_processing.cpp gibsong_pre_processing.hpp gibsong_stats.o gibsong_vector_ops.o
	$(CC) -o $@ $^
all: gibsong_vector_ops.o stats prep
clean:
	rm -f *.o
	rm -f hist
	rm -f *.gch
	rm -f *.csv