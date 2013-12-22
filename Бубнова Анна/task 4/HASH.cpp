#include <stdio.h>
#include <alloc.h>
#include <string.h>
#define TABLE_SIZE 4096
int
hash (unsigned char *s) 

{
  long int h = 0;
  while (*s)
    h = (h*31+*s++)%TABLE_SIZE;
  return h;
}

struct List{
	unsigned char *s;
  List *n;
  int count;
};
#define MAX_L 1000
int main(int _argc,unsigned char *_argv[]){
//	printf("%lu\n",(unsigned long) coreleft());
//	return 0;
	unsigned long int oldcoreleft=coreleft();
	unsigned char *alph="јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№ЁёяабвгдеЄжзийклмнопрстуфхцчшщъыьэю€";
	unsigned char downcase[256];//если не буква, то 0
	int i;
  for (i=0;i<256;i++)
    downcase[i]=0;
  for (i='A';i<='Z';i++)
		downcase[i]=i+32;
  for (i='a';i<='z';i++)
    downcase[i]=i;
  for (i=0;i<33;i++){
    downcase[alph[i+33]]=alph[i+33];
    downcase[alph[i]]=alph[i+33];
  };

  List *t[TABLE_SIZE];
	int cl[TABLE_SIZE],maxcl=0;
  for (i=0;i<TABLE_SIZE;i++){
    t[i]=0;
		cl[i]=0;
  };
	long int wordCount=0,charCount=0,emptyCount=TABLE_SIZE;
  FILE *f=fopen(_argv[1],"rt");
  if (!f)
    return 1;
	unsigned char s[MAX_L],w[MAX_L];
	while (fgets(s,MAX_L,f)){
		unsigned char *_=s;
		do {
			while ((*_)&&(!downcase[*_]))
				_++;
			for (unsigned char *w_=w;*w_=downcase[*_];_++,w_++);
			if (w_!=w){
				int hashw=hash(w);
				List *l=t[hashw],*lold=NULL;
				//add/increase
				int cmpres=1;
				while ((l)&&(cmpres>0)){
					cmpres=strcmp(w,l->s);
					if (cmpres>0){
						lold=l;
						l=l->n;
					};
				};
				if (!cmpres)
					l->count++;
						else{//create
							List* newl=(List *)malloc(sizeof(List));
							newl->n=l;
							newl->count=1;
							newl->s=(unsigned char *)malloc(w_-w+1);
							strncpy(newl->s,w,w_-w+1);
							if (lold)
								lold->n=newl;
								else{
									if (!t[hashw])
										emptyCount--;
									t[hashw]=newl;
								};
							wordCount++;
							cl[hashw]++;
							if (cl[hashw]>cl[maxcl])
								maxcl=hashw;
						};
			};
		} while (*_);
		charCount+=strlen(s);
//		printf("%s\r",s);
//		printf("%8ld %8ld %8lu\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
//					 charCount,wordCount,(unsigned long int) coreleft());
	};
	fclose(f);
	printf("„исло использований каждого слова посчитано.\n");
	printf("load factor=%f, средн€€/максимальна€ длина цепочки %f/%d\n",
				 ((double)wordCount)/TABLE_SIZE,
				 ((double)wordCount)/(TABLE_SIZE-emptyCount),cl[maxcl]);
	printf("значени€, которые в нее попали :");
	{
		for (List *l=t[maxcl];l;l=l->n)
			printf("%s(%d)%c",l->s,l->count,(l->n==NULL)?'\n':' ');
	};
	printf("общее число добавленных слов %ld, число пустых €чеек таблицы %ld\n",
				 wordCount,emptyCount);
	printf("»спользовано %lu байт пам€ти\n",(unsigned long) oldcoreleft-coreleft());
	return 0;
};