OBJS = Neuron.o NeuronLayer.o NeuralNet.o Genome.o main.o
CC = g++
CFLAGS = -g -Wall -std=c++11
LFLAGS = -g -Wall

minesweeper: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o minesweeper

Neuron.o: Neuron.cpp Neuron.h
	$(CC) $(CFLAGS) -c Neuron.cpp

NeuronLayer.o: NeuronLayer.cpp NeuronLayer.h Neuron.h
	$(CC) $(CFLAGS) -c NeuronLayer.cpp

NeuralNet.o: NeuralNet.cpp NeuralNet.h NeuronLayer.h
	$(CC) $(CFLAGS) -c NeuralNet.cpp

Genome.o: Genome.cpp Genome.h
	$(CC) $(CFLAGS) -c Genome.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) minesweeper *.o
