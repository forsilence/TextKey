# include"../include/TextKey.h"
# include"../include/StringKey.h"
# include<fstream>
# include<iostream>
namespace Keys{
TextLoadKey::TextLoadKey(std::string loadFile_):loadFile(loadFile_),file(),wordsInRows(){}
TextLoadKey& TextLoadKey::setLoadFile(std::string loadFile_){
  StringKey sk(loadFile_);
  loadFile = sk.trim().getHandledString();
  return *this;
}

TextLoadKey& TextLoadKey::load(){
  std::ifstream loadFileStream;
  loadFileStream.open(loadFile,std::ifstream::in);
  if(!loadFileStream){
    throw "file not exist!";
  }
  std::string line;
  StringKey sk("");
  while(std::getline(loadFileStream,line)){
    file.push_back(line);
    sk.setHandleString(line);
    for(std::string it:sk.splitToWords()){
      auto findingWord = wordsInRows.find(it);
      if(findingWord!=wordsInRows.end()){
        findingWord->second.push_back(file.size()-1);
      }else{
        wordsInRows[it]=std::vector<int>(1,file.size()-1);
      }
    }
  }
  return *this;
}

std::vector<std::string> TextLoadKey::getFile() const{
  return file;
}

std::map<std::string,std::vector<int> > TextLoadKey::getWordsInRow() const{
  return wordsInRows;
}

std::string TextHandleKey::getLineByRowNumber(std::size_t rowNumber){
  return file[rowNumber];
}
std::vector<int> TextHandleKey::getRowsOf(std::string str_) const{
  std::vector<int> Rows;
  try{
    Rows = wordsInRows.at(str_);
  }catch(std::out_of_range e){
    ;
  }
  return Rows;
}
namespace Test{
void TextLoadTest::testing(){
  std::string loadFile("../data/TextLoadTest.txt");
  TextLoadKey tlk(loadFile);
  tlk.load();
  auto file = tlk.getFile();
  auto wordsInrows = tlk.getWordsInRow();
  for(auto& line:file){
    std::cout << line << std::endl;
  }
  for(auto& item:wordsInrows){
    std::cout << "word [" << item.first << "] in row " ;
    for(int row:item.second){
      std::cout << "[" << row << "]";
    }
    std::cout << std::endl;
  }
}
void TextHandleTest::testing(){
  std::string loadFile("../data/TextLoadTest.txt");
  TextLoadKey tlk(loadFile);
  tlk.load();
  TextHandleKey thk(tlk);
  std::string str_;
  while(str_!="#"){
    std::cout << "input word you are looking for (# exit) : " ;
    std::cin >> str_;
    if(str_!="#"){
      std::cout << std::endl << "result: " << std::endl;
      for(auto rowNumber:thk.getRowsOf(str_)){
        std::cout << "[" << rowNumber << "]";
      }
      std::cout << std::endl;
    }
  }
}
}
} // Keys