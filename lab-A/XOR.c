

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "XOR.h"
XOR_LIST* Create_Element(char* str)
{
	XOR_LIST* New = (XOR_LIST*)malloc(sizeof(XOR_LIST));
	if (New == NULL)
	{
		printf("ERROR!!! Unable to give memory\n");
		return NULL;
	}
	New->a = str;
	New->key = NULL;
	return New;
}
void Iteration(XOR_LIST** Prev, XOR_LIST** Cur, int it)
{
	if (*Prev == *Cur)
	{
		printf("Imposible to move thorought the list, both pointers are equal \n");
		return;
	}
	XOR_LIST* Space;
	if (it < 0)
	{
		while (it != 0)
		{
			if ((*Prev)->key == (*Cur))
			{
				printf("You have met the left end of the list, return Current Position\n");
				return;
			}
			Space = (XOR_LIST*)((long long)(*Prev)->key ^ (long long)(*Cur));
			*Cur = *Prev;
			*Prev = Space;
			it++;
		}
		return;
	}
	if (it > 0)
	{
		while (it != 0)
		{
			if ((*Cur)->key == (*Prev))
			{
				printf("You have met the right end of the list, return Current Position\n");
				return;
			}
			Space = (XOR_LIST*)((long long)(*Cur)->key ^ (long long)(*Prev));
			*Prev = *Cur;
			*Cur = Space;
			it--;
		}
		return;
	}
	return;
}
XOR_LIST* Add_Element(char* Str, XOR_LIST* Prev, XOR_LIST* Cur)
{
	XOR_LIST* New = Create_Element(Str);
	if (New == NULL)
	{
		return NULL;
	}
	if (Prev == Cur)
	{
		printf("Immposible to add an element in these conditions!\n");
		New->key = NULL;
		return New;
	}
	else if (Prev == NULL)
	{
		XOR_LIST* Next = Cur->key;
		New->key = Cur;
		Cur->key = (XOR_LIST*)((long long)New ^ (long long)Next);
		return New;
	}
	else if (Cur == NULL)
	{
		XOR_LIST* PrevPrev = Prev->key;
		New->key = Prev;
		Prev->key = (XOR_LIST*)((long long)PrevPrev ^ (long long)New);
		return New;
	}
	else
	{
		XOR_LIST* Help1 = (XOR_LIST*)((long long)Prev->key ^ (long long)Cur);
		XOR_LIST* Help2 = (XOR_LIST*)((long long)Cur->key ^ (long long)Prev);
		New->key = (XOR_LIST*)((long long)Prev ^ (long long)Cur);
		Prev->key = (XOR_LIST*)((long long)Help1 ^ (long long)New);
		Cur->key = (XOR_LIST*)((long long)Help2 ^ (long long)New);
		return New;
	}
}
int Delete_Key(XOR_LIST** Start, char* Key)
{
	if (*Start == NULL || Key == NULL)
	{
		printf("Immpposible to delete anything\n");
		return 0;
	}
	XOR_LIST* Prev = NULL;
	XOR_LIST* CurCur = *Start;
	XOR_LIST* Next = NULL;
	while (CurCur != NULL)
	{
		if (strcmp(CurCur->a, Key) == 0)
		{
			if (Prev == NULL)
			{
				Next = CurCur->key;
				if (Next != NULL)
				{
					XOR_LIST* NextNext = (XOR_LIST*)((long long)Next->key ^ (long long)CurCur);
					Next->key = NextNext;
				}
				*Start = Next;
			}
			else
			{
				XOR_LIST* PrevPrev = (XOR_LIST*)((long long)Prev->key ^ (long long)CurCur);
				Next = (XOR_LIST*)((long long)CurCur->key ^ (long long)Prev);
				Prev->key = (XOR_LIST*)((long long)PrevPrev ^ (long long)Next);
				if (Next != NULL)
				{
					XOR_LIST* NextNext = (XOR_LIST*)((long long)Next->key ^ (long long)CurCur);
					Next->key = (XOR_LIST*)((long long)Prev ^ (long long)NextNext);
				}
			}
			free(CurCur->a);
			free(CurCur);
			return 1;
		}
		if (Prev == NULL)
		{
			Next = CurCur->key;
			Prev = CurCur;
			CurCur = Next;
		}
		else
		{
			Next = (XOR_LIST*)((long long)CurCur->key ^ (long long)Prev);
			Prev = CurCur;
			CurCur = Next;
		}
	}
	printf("There is no such an element in list\n");
	return 0;
}
int Delete_Adress(XOR_LIST** Start, XOR_LIST* Delete)
{

	if (*Start == NULL || Delete == NULL)
	{
		printf("Impossible to delete any element\n");
		return 0;
	}


	if (*Start == Delete)
	{
		XOR_LIST* Next = (*Start)->key;
		if (Next != NULL)
		{

			XOR_LIST* NextNext = (XOR_LIST*)((uintptr_t)Next->key ^ (uintptr_t)*Start);
			Next->key = NextNext;
		}
		free((*Start)->a);
		free(*Start);
		*Start = Next;
		return 1;
	}
	XOR_LIST* Prev = NULL;
	XOR_LIST* Current = *Start;
	XOR_LIST* Next = NULL;

	while (Current != NULL)
	{

		if (Prev == NULL)
		{
			Next = Current->key;
		}
		else
		{
			Next = (XOR_LIST*)((uintptr_t)Current->key ^ (uintptr_t)Prev);
		}


		if (Current == Delete)
		{

			if (Prev != NULL)
			{
				XOR_LIST* PrevPrev = (XOR_LIST*)((uintptr_t)Prev->key ^ (uintptr_t)Current);
				Prev->key = (XOR_LIST*)((uintptr_t)PrevPrev ^ (uintptr_t)Next);
			}

			if (Next != NULL)
			{
				XOR_LIST* NextNext = (XOR_LIST*)((uintptr_t)Next->key ^ (uintptr_t)Current);
				Next->key = (XOR_LIST*)((uintptr_t)NextNext ^ (uintptr_t)Prev);
			}


			free(Current->a);
			free(Current);
			return 1;
		}
		Prev = Current;
		Current = Next;
	}
	printf("There is no such element\n");
	return 0;
}
XOR_LIST* Find_Key(XOR_LIST* Start, char* Key)
{
	XOR_LIST* Prev = NULL;
	XOR_LIST* Cur = Start;
	XOR_LIST* Next = NULL;

	while (Cur != NULL)
	{
		if (strcmp(Cur->a, Key) == 0)
		{
			return Cur;
		}
		if (Prev == NULL)
		{
			Next = Cur->key;
			Prev = Cur;
			Cur = Next;
		}
		else
		{
			Next = (XOR_LIST*)((long long)Cur->key ^ (long long)Prev);
			Prev = Cur;
			Cur = Next;
		}
	}
	printf("There is no such Element in list\n");
	return NULL;
}
XOR_LIST* Fill_List_Help(int first, int second, XOR_LIST** Prev, XOR_LIST** Cur, int third, int fourth, XOR_LIST** Start, XOR_LIST** Neighbour)
{
	char* List[5] = { "A","B","C","D","E" };
	XOR_LIST* ListPointers[5];
	for (int i = 0; i < 5; i++)
	{
		XOR_LIST* New = (XOR_LIST*)malloc(sizeof(XOR_LIST));
		if (New == NULL)
		{
			printf("ERROR!!! Unable to give memory\n");
			return NULL;
			for (int j = 0; j < i; j++)
			{
				free(ListPointers[j]->a);
				free(ListPointers[j]);
			}
		}
		New->a = _strdup(List[i]);
		New->key = NULL;
		ListPointers[i] = New;
	}

	ListPointers[0]->key = ListPointers[1];

	ListPointers[1]->key = (XOR_LIST*)((long long)ListPointers[0] ^ (long long)ListPointers[2]);

	ListPointers[2]->key = (XOR_LIST*)((long long)ListPointers[1] ^ (long long)ListPointers[3]);

	ListPointers[3]->key = (XOR_LIST*)((long long)ListPointers[2] ^ (long long)ListPointers[4]);

	ListPointers[4]->key = ListPointers[3];

	*Prev = ListPointers[first];

	*Cur = ListPointers[second];

	*Start = ListPointers[third];

	*Neighbour = ListPointers[fourth];

	return ListPointers[0];
}
void Clear_List_Help(XOR_LIST** Start)
{
	if (*Start == NULL)
	{
		return;
	}
	XOR_LIST* Prev = NULL;
	XOR_LIST* Cur = *Start;
	XOR_LIST* Next = NULL;
	while (Cur != NULL)
	{
		if (Prev == NULL)
		{
			Next = Cur->key;
		}
		else
		{
			Next = (XOR_LIST*)((long long)Cur->key ^ (long long)Prev);
		}
		free(Cur->a);
		free(Cur);
		Prev = Cur;
		Cur = Next;
	}
	*Start = NULL;
}
int Orig_main()
{
	return 0;
}