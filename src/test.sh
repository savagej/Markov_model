#! /bin/sh
make 
cd ../test
../src/markov distances.txt adjacency.txt test_output.txt
cd ../src
