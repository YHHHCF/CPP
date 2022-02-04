echo "======== Begin compiling ========"
g++ -std=c++11 -o shared_ptrs shared_ptrs.cpp StrBlob.cpp;
echo "========= Begin running ========="
./shared_ptrs
