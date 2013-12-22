#include <stdlib.h>
#include <mem.h>
//если что, копирование можно переписать вручную
//int i=0;
//for (char *dest=this->s,*src=s;i<len;*(dest++)=*(src++),i++);
class String{
 public:
  char *s;
  long int len;
  String create(){
    s=NULL;
    len=0;
    return *this;
  };
  String create(long int len){
    s=(char *)malloc(len);
    this->len=len;
    return *this;
  };
  String create(char *s){
    char *i=s;
    for (;*i;i++);
    len=i-s-1;//нулевой байт в конце не берём. может зря
    //да, будет неудобно с указателем на char
    //но у нас же есть длина 
    this->s=(char *)malloc(len);
    memcpy(this->s,s,len);
    return *this;
  };
  void del(){
    free(s);
    return;
  };
  String concat(String hvost){//tail не звучит тут как-то, а s
  //уже трогать не хочется из за возможной путаницы
    char *news=(char *)malloc(len+hvost.len);
    if (s){
      memcpy(news,s,len);
      free(s);
    };
    s=news;
    if (hvost.s)
      memcpy(news+len,hvost.s,hvost.len);
    len+=hvost.len;
    return *this;
  };
  String substr(long int index,long int count){
    String res;
    if (count>len-index)
      count=len-index;
    res.create(count);
    memcpy(res.s,s+index,count);
    return res;
  };
  int cmp(String h){ // <0 если *this<h
    long int efflen=(h.len>len)?len:h.len;
    char *lim=s+efflen,*s_=s,*h_=h.s;
    for (;(s_<lim)&&(*s_==*h_);s_++,h_++);
    if (s_==lim)
      if (h.len==len)
       return 0; else
        return (h.len>len)?-(int)*h_:(int)*s_; else
        return (int)*s_-(int)*h_;
  };
  String clone(){
    String s;
    s.create();
    s.concat(*this);
    return s;
  };
  long int length(){
    return len;
  };
  long int isEmpty(){
    return !len;
  };
  char* toChar(){
    return s;
  };
  int operator== (String s){
    if (s.len!=len)
      return 0;
    return !cmp(s);
  };
  ~String(){
    if (s)
      free(s);
  };
};
