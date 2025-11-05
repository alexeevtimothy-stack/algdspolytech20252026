


#include <gtest/gtest.h>

extern "C" {
#include "../Source/XOR.h"
}

TEST(XOR_TEST, Iteration_No_1) {
	XOR_LIST* A;
	XOR_LIST* B;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(3, 4, &A, &B, 1, 2, &F, &G);

	Iteration(&F, &G, 10000);

	EXPECT_EQ(F, A);
	EXPECT_EQ(G, B);

	EXPECT_EQ(F->a, A->a);
	EXPECT_EQ(G->a, B->a);

	EXPECT_EQ(F->key, A->key);
	EXPECT_EQ(G->key, B->key);

	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Iteration_No_2) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(2, 3, &B, &C, 3, 4, &F, &G);

	Iteration(&F, &G, -1);

	EXPECT_EQ(F, B);
	EXPECT_EQ(G, C);

	EXPECT_EQ(F->a, B->a);
	EXPECT_EQ(G->a, C->a);

	EXPECT_EQ(F->key, B->key);
	EXPECT_EQ(G->key, C->key);

	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Iteration_No_3) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 4, 4, &F, &G);

	Iteration(&F, &G, 1);

	EXPECT_EQ(F, B);
	EXPECT_EQ(G, C);

	EXPECT_EQ(F->a, B->a);
	EXPECT_EQ(G->a, C->a);

	EXPECT_EQ(F->key, B->key);
	EXPECT_EQ(G->key, C->key);

	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Iteration_No_4) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(2, 3, &B, &C, 2, 3, &F, &G);
	Iteration(&F, &G, 0);

	EXPECT_EQ(F, B);
	EXPECT_EQ(G, C);

	EXPECT_EQ(F->a, B->a);
	EXPECT_EQ(G->a, C->a);

	EXPECT_EQ(F->key, B->key);
	EXPECT_EQ(G->key, C->key);

	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Iteration_No_5) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(1, 2, &B, &C, 2, 3, &F, &G);
	Iteration(&G, &F, 1);

	EXPECT_EQ(F, B);
	EXPECT_EQ(G, C);

	EXPECT_EQ(F->a, B->a);
	EXPECT_EQ(G->a, C->a);

	EXPECT_EQ(F->key, B->key);
	EXPECT_EQ(G->key, C->key);

	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Add_Element_No_6) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(1, 2, &B, &C, 2, 3, &F, &G);
	char a[] = "ERORRR";
	char* A = _strdup(a);
	XOR_LIST* H = Add_Element(A, B, C);
	ASSERT_TRUE(H);
	EXPECT_EQ(H->a, A);
	EXPECT_EQ(H->key, (XOR_LIST*)((long long)B ^ (long long)C));
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Add_Element_No_7) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "ERORRR";
	char* A = _strdup(a);
	XOR_LIST* H = Add_Element(A, nullptr, B);
	Start = H;
	ASSERT_TRUE(H);
	EXPECT_EQ(H->a, A);
	EXPECT_EQ(H->key, B);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Add_Element_No_8) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "ERORRR";
	char* A = _strdup(a);
	XOR_LIST* H = Add_Element(A, C, nullptr);
	ASSERT_TRUE(H);
	EXPECT_EQ(H->a, A);
	EXPECT_EQ(H->key, C);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Add_Element_No_9) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "ERORRR";
	char* A = _strdup(a);
	XOR_LIST* H = Add_Element(A, B, C);
	ASSERT_TRUE(H);
	EXPECT_EQ(H->a, A);
	EXPECT_EQ(H->key, nullptr);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Key_No_10) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "C";
	char* A = _strdup(a);
	int H = Delete_Key(&Start, A);
	EXPECT_EQ(H, 1);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Key_No_11) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "A";
	char* A = _strdup(a);
	int H = Delete_Key(&Start, A);
	EXPECT_EQ(H, 1);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Key_No_12) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 2, 3, &F, &G);
	char a[] = "77";
	char* A = _strdup(a);
	int H = Delete_Key(&Start, A);
	EXPECT_EQ(H, 0);
	if (H == 0 && A != NULL) {
		free(A);
	}
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Key_No_13) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(4, 4, &B, &C, 2, 3, &F, &G);
	char* A = nullptr;
	int H = Delete_Key(&Start, A);
	EXPECT_EQ(H, 0);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Key_No_14) {
	XOR_LIST* Start = NULL;
	char* A = _strdup("4");
	int H = Delete_Key(&Start, A);
	EXPECT_EQ(H, 0);
	free(A);
}
TEST(XOR_TEST, Delete_Adress_No_15) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	int H = Delete_Adress(&Start, C);
	EXPECT_EQ(H, 1);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Adress_No_16) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	int H = Delete_Adress(&Start, B);
	EXPECT_EQ(H, 1);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Adress_No_17) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* K = (XOR_LIST*)2556;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	int H = Delete_Adress(&Start, K);
	EXPECT_EQ(H, 0);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Adress_No_18) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* K = (XOR_LIST*)2556;
	XOR_LIST* Start = NULL;
	int H = Delete_Adress(&Start, K);
	EXPECT_EQ(H, 0);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Delete_Adress_No_19) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* K = NULL;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	int H = Delete_Adress(&Start, K);
	EXPECT_EQ(H, 0);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Find_Key_Adress_No_19) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* FOUND;
	XOR_LIST* Start = Fill_List_Help(0, 4, &B, &C, 2, 3, &F, &G);
	char* a = _strdup("A");
	FOUND = Find_Key(Start, a);
	EXPECT_EQ(FOUND, B);
	Clear_List_Help(&Start);
}
TEST(XOR_TEST, Find_Key_Adress_No_20) {
	XOR_LIST* B;
	XOR_LIST* C;
	XOR_LIST* F;
	XOR_LIST* G;
	XOR_LIST* FOUND;
	XOR_LIST* Start = NULL;
	char* a = _strdup("A");
	FOUND = Find_Key(Start, a);
	EXPECT_EQ(FOUND, nullptr);
	free(a);
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}