g++ -std=c++11 -c main.cpp;
g++ -std=c++11 -c Sales_data.cpp;
g++ -std=c++11 -c Screen.cpp;
g++ -std=c++11 main.o Sales_data.o -o prog;

echo "========= Begin running ========="
./prog
