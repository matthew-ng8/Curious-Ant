#define MAX_SIZE 100

typedef struct{
	int x, y;
}pos;

int isempty (void);
int isfull (void);
pos peek (void); 
pos pop (void);
void push (pos);
void clear (void);

