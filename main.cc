# include<iostream>
# include<string>
# include"include/StringKey.h"
# include"include/TextKey.h"

int main(){
  std::cout << "TextKey" << std::endl;
  // Keys::Test::StringKeyTest skTest;
  // skTest.testing();
  Keys::Test::TextHandleTest tlt;
  tlt.testing();
  return 0;
}