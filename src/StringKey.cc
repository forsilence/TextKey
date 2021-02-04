# include"../include/StringKey.h"
# include<iostream>
namespace Keys{
StringKey::StringKey(std::string str_){
  str = str_;
  handledString = str;
}
StringKey& StringKey::setHandleString(std::string str_){
  str = str_;
  handledString = str;
  return *this;
}

StringKey& StringKey::trim(){
  if(handledString.size()!=0){
    std::size_t front = 0;
    std::size_t back = handledString.size() - 1;
    while(front<back && handledString[front]==' '){
      ++front;
    }
    while(front<back && handledString[back]==' '){
      --back;
    }
    handledString=handledString.substr(front,back-front + 1);
  }
  return *this;
}

std::vector<std::string> StringKey::splitToWords(){
  std::vector<std::string> words;
  std::size_t begin = 0;
  std::size_t len = 0;
  std::istringstream istrStream(handledString);
  std::string word("");
  while(istrStream >> word){
    words.push_back(word);
  }
  return words;
}
std::string StringKey::getHandledString() const{
  return handledString;
}

bool StringKey::isCapitalLetter(char c){
  if(c>='A' && c<='Z'){
    return true;
  }else{
    return false;
  }
}

bool StringKey::isLowerCaseLetter(char c){
  if(c>='a' && c<='z'){
    return true;
  }else{
    return false;
  }
}

char StringKey::LowerLetter(char c){
  if(isCapitalLetter(c)){
    return c + 'a'-'A';
  }else{
    return c;
  }
}

char StringKey::UpperLetter(char c){
  if(isLowerCaseLetter(c)){
    return c + 'A' - 'a';
  }else{
    return c;
  }
}
StringKey& StringKey::Lower(){
  for(int loc=0; loc<handledString.size() ; ++loc){
    if(isCapitalLetter(handledString[loc])){
      handledString[loc] = LowerLetter(handledString[loc]);
    }
  }
  return *this;
}
StringKey& StringKey::Upper(){
  for(int loc=0; loc<handledString.size(); ++loc){
    if(isLowerCaseLetter(handledString[loc])){
      handledString[loc] = UpperLetter(handledString[loc]);
    }
  }
  return *this;
}

namespace Test{
void StringKeyTest::testing(){
  std::cout << "StringKeyTest" << std::endl;
  std::string testString("  String Key Test  ");
  std::cout << " test string is : [" << testString << "]" << std::endl;
  StringKey sk(testString);
  std::cout << " after trim : [" << sk.trim().getHandledString() << "]" << std::endl;
  std::cout << "after split to words : ";
  for(auto it:sk.splitToWords()){
    std::cout << "[" << it << "]";
  }
  std::cout << std::endl;
  std::cout << "Upper string : [" << sk.Upper().getHandledString() << "]" << std::endl;
  std::cout << "Lower String : [" << sk.Lower().getHandledString() << "]" << std::endl;
}
} // Test
} // Keys