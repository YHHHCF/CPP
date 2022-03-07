echo "======== Begin compiling ========"
g++ -std=c++11 -c Quote.cpp;
g++ -std=c++11 -c Disc_quote.cpp;
g++ -std=c++11 -c Bulk_quote.cpp;
g++ -std=c++11 -c Basket.cpp;
g++ -std=c++11 -c main.cpp;

g++ -std=c++11 main.o Quote.o Disc_quote.o Bulk_quote.o Basket.o -o prog;
echo "========= Begin running ========="
./prog
