#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

void print_set(const set<string> &s, string str) {
    cout << str << ": ";
    for (const auto &item : s) {
        cout << item << " ";
    }
    cout << endl;
}

void print_set(const multiset<string> &s, string str) {
    cout << str << ": ";
    for (const auto &item : s) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    // 1. map and set
    map<string, int> m1 = {{"abcd", 300}, {"bcde", 400}};
    m1["erbao"] = 100;
    m1["huang"] = 200;

    for (const auto &item : m1) {
        cout << item.first << ", " << item.second <<endl;
    }

    set<string> s1 = {"erbao", "huang"};
    print_set(s1, "s1");
    // begin, end, find returns iterator
    cout << (*(m1.begin())).first << endl;

    cout << *(s1.begin()) << ", " << *(--s1.end()) << endl;
    cout << *(s1.find("erbao")) << endl;

    // 2. multimap and multiset
    set<string> s2 = {"erbao", "huang", "erbao"};
    print_set(s2, "s2");

    // multiset could contain multiple items with the same value
    multiset<string> s2m = {"erbao", "huang", "erbao"};
    print_set(s2m, "s2m");

    multimap<string, int> m2m = {{"abcd", 300}, {"bcde", 400}, {"abcd", 500}};

    for (const auto &item : m2m) {
        cout << item.first << ", " << item.second <<endl;
    }

    // 3. pair
    pair<string, int> p1("erbao", 200);
    cout << p1.first << ", " << p1.second << endl;

    pair<string, int> p2 = make_pair("erbao", 100); 
    cout << p2.first << ", " << p2.second << endl;

    // empty pair will be default initialized
    pair<string, int> p3 = pair<string, int>();
    cout << p3.first << ", " << p3.second << endl;

    // 4. types
    set<string>::key_type v1 = "str";
    set<string>::value_type v2 = "str";
    map<string, int>::key_type v3 = "str";
    map<string, int>::mapped_type v4 = 3;
    map<string, int>::value_type v5 = make_pair("name", 10);

    // 5. iterator
    auto map_it = m1.begin(); // iterator is of value_type
    cout << (*(map_it)).first << ", " << map_it->second << endl;
    ++map_it;
    cout << map_it->first << ", " << (*(map_it)).second << endl;

    auto set_it = s1.begin();
    cout << *set_it << endl;
    ++set_it;
    cout << *set_it << endl;

    // *set_it = "huang"; // const iterator, cannot modify
    cout << "debug 5" << endl;
    // iterator order is key order, default alphabetically
    for (auto map_it = m1.cbegin(); map_it != m1.cend(); ++ map_it) {
        cout << map_it->first << ", " << map_it->second << endl;
    }

    map<int, int> m;
    m[1] = 2;
    m[2] = 3;
    ++m[2];
    m[0] = 9;
    m[6] = 10;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        cout << it->first << ", " << it->second << endl;
    }

    // 6. operations
    // 6.1 insert
    s1.insert("hh"); // insert to set

    // returns a pair, first element is the iterator of the item
    // second element is whether insertion succeeds
    auto ret = m1.insert({"hhh", 11});
    cout << (ret.first)->first << ", " << (ret.first)->second \
         << ", " << ret.second << endl;

    // insertion failed and return already existing kv pair in map
    ret = m1.insert({"erbao", 111});
    cout << (ret.first)->first << ", " << (ret.first)->second \
         << ", " << ret.second << endl;

    // inserts to a multiple map
    multimap<string, int> mulmap;
    mulmap.insert({"erbao", 1});
    mulmap.insert({"erbao", 1});
    mulmap.insert({"erbao", 2});
    cout << mulmap.size() << endl;

    // 6.2 erase
    cout << m1.size() << endl;
    m1.erase(m1.begin()); // using iterator
    cout << m1.size() << endl;
    m1.erase("erbao"); // using key
    cout << m1.size() << endl;

    cout << s1.size() << endl;
    s1.erase("erbao");
    cout << s1.size() << endl;
    s1.erase(s1.begin());
    cout << s1.size() << endl;

    // 6.3 subscribe
    cout << "6.3: " << m1.size() << endl;
    m1["aaa"] = 2;
    cout << m1["aaa"] << ", " << m1.size() << endl;
    m1["aaa"] = 3;
    cout << m1["aaa"] << ", " << m1.size() << endl;
    m1["aaaaaaa"]; // this adds to map
    cout << m1.size() << endl;

    cout << m1.at("aaa") << ", " << m1.at("aaaaaaa") << endl;
    // cout << m1.at("bbb") << endl; // runtime out of range exception

    // 6.4 access
    set<int> iset = {1, 1, 2, 3, 4};
    // if not exists return end() iterator
    cout << *(iset.find(3)) << endl;
    cout << &(*(--iset.find(7))) << ", " \
         << &(*(--iset.end())) << ": " << *(--iset.find(7)) << endl;

    cout << iset.count(1) << endl;
    cout << mulmap.count("erbao") << endl; // #of key repeats

    // 7. unordered container (use if no key order, better performance)
    unordered_map<string, int> umap;
    umap["erbao"] = 1;
    umap["huang"] = 2;
    for (auto &kv : umap) {
        cout << kv.first << ": " << kv.second << endl;
        if (kv.first == "erbao") kv.second = 11;
    }

    for (auto &kv : umap) {
        cout << kv.first << ": " << kv.second << endl;
    }

    return 0;
}
