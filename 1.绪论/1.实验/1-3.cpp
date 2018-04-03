#include <string>
#include <iostream>
using namespace std;
string keys[] = {"asm","auto","bool","break","case","catch","char","class","const","const_cast","continue","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace","new","operator","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_cast","struct","switch","template","this","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","alignas","alignof","char16_t","char32_t","constexpr","decltype","noexcept","nullptr","static_assert","thread_local"};
bool isKey(const string keys[],const string key)
{
  for(int i = 0; i < 73; i++)
    if(keys[i]==key)
      return true;
  return false;
}

int
main()
{
  bool is;
  string str;
  cin>>str;
  is = isKey(keys,str);
  return 0;
}
