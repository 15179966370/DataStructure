

typedef int elemtype;


typedef struct node_tag{

    elemtype data;

    struct node_tag *next,*proir;
}DBNDOE,*DBNODEPTR,*DBLINKLIST;






extern void DeleteElemDBLinkList(DBNODEPTR p);

extern int InsertElemAfterDB(DBNODEPTR p,elemtype e);
