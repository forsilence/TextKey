# if !defined(_STRING_kEY_H)
# define _STRING_kEY_H
# include<vector>
# include<sstream>
# include<string>
# include"KeyTest.h"
namespace Keys{
class StringKey{
  public:
  StringKey(std::string str_);
  StringKey& setHandleString(std::string str_);
  std::vector<std::string> splitToWords();
  StringKey& trim();
  std::string getHandledString() const;
  bool isCapitalLetter(char c);
  bool isLowerCaseLetter(char c);
  char UpperLetter(char c);
  char LowerLetter(char c);
  StringKey& Upper();
  StringKey& Lower();
  private:
  std::string handledString;
  std::string str;
};
namespace Test{
class StringKeyTest: public BaseKeyTest{
  public:
  void testing() override;
};
} // Test
} // Keys
# endif