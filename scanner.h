#include "stack.h"
#define LEN 100


pos currentPos, exitPos;
char numofcolumns[LEN], numofrows[LEN];
char mazestorer[LEN][LEN];

int t, n;

typedef enum{MVF, MVB, MVL, CWL, MWR, CWR, CWF, CWB, PUSH, POP, PEEK, CLEAR, BJPI, CJPI
}act;

//act *p;

act intelligence[LEN];
