# compile and link together
# g++ -std=c++11 main.cpp function.cpp -o main;

# seperate compile and link
g++ -std=c++11 -c main.cpp;
g++ -std=c++11 -c function.cpp;
g++ -std=c++11 main.o function.o -o prog;

echo "========= Begin running ========="
./prog
