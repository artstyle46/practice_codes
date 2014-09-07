/*==========  Permutation of a string (Only non-repeating characters allowed)  ==========*/

#include <iostream>
#include <cstring>
#include <cassert>
#include <map>

void permuteString(std::string a, std::string b) {
	if (b.empty())
		std::cout << a << std::endl;

	else 
		for (int i = 0; i < b.length(); i++)
			permuteString(a + b[i], b.substr(0, i) + b.substr(i + 1));
}

bool isUnique(std::string s) {
  std::map<char, int> table;
  for (int i = 0; i < s.length(); ++i)
    table[s[i]]++;

  std::map<char, int>::iterator it;
  it = table.begin();
  while(it != table.end()) {
    if (it->second > 1)
      return false;
    ++it;
  }
  return true;
}

int main() {
  std::string s;
  std::cout << "Enter a string with unique characters : \n";
  std::cin >> s;

  assert(isUnique(s));

	permuteString("", s);
	
  return 0;
}