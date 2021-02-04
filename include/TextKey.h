# if !defined(_TEXT_LOAD_KEY_H)
# define _TEXT_LOAD_KEY_H
# include<vector>
# include<map>
# include<string>
# include"KeyTest.h"
namespace Keys{
class TextLoadKey{
  public:
  typedef std::map<std::string,std::vector<int> > word_row_map;
  TextLoadKey(std::string loadFile);
  TextLoadKey& load();
  TextLoadKey& setLoadFile(std::string loadFile);
  std::vector<std::string> getFile() const ;
  std::map<std::string,std::vector<int> > getWordsInRow() const ;
  private:
  std::string loadFile;
  std::vector<std::string> file;
  std::map<std::string,std::vector<int> > wordsInRows;
};
class TextHandleKey{
  public:
  typedef std::map<std::string,std::vector<int> > word_row_map;
  TextHandleKey(const TextLoadKey& loader):file(loader.getFile()),wordsInRows(loader.getWordsInRow()){}
  std::string getLineByRowNumber(std::size_t rowNumber);
  std::vector<int> getRowsOf(std::string str_) const;
  private:
  std::vector<std::string> file;
  word_row_map wordsInRows;
};
namespace Test{
class TextLoadTest: public BaseKeyTest{
  public:
  void testing() override;
};
class TextHandleTest: public BaseKeyTest{
  public:
  void testing() override;
};
}
} // Keys
# endif