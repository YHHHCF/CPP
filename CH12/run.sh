echo "======== Begin compiling ========"
g++ -std=c++11 smart_ptrs.cpp StrBlob.cpp -o smart_ptrs;
echo "========= Begin running ========="
./smart_ptrs
