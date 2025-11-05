


#ifndef XOR_H
#define XOR_H

typedef struct XOR_LIST
{
	char* a;
	struct XOR_LIST* key;
} XOR_LIST;
XOR_LIST* Create_Element(char* str);
void Iteration(XOR_LIST** Prev, XOR_LIST** Cur, int it);
XOR_LIST* Add_Element(char* Str, XOR_LIST* Prev, XOR_LIST* Cur);
int Delete_Key(XOR_LIST** Start, char* Key);
int Delete_Adress(XOR_LIST** Start, XOR_LIST* Delete);
XOR_LIST* Find_Key(XOR_LIST* Start, char* Key);
XOR_LIST* Fill_List_Help(int first, int second, XOR_LIST** Prev, XOR_LIST** Cur, int third, int fourth, XOR_LIST** Start, XOR_LIST** Neighbour);
void Clear_List_Help(XOR_LIST** Start);

#endif