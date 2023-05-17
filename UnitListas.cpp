//---------------------------------------------------------------------------

#include <functional>
#include <iostream>
#include <queue>
#include <vcl.h>
#include <vector>
#pragma hdrstop
struct ListNode
{
   int val;
   ListNode *next;
};

#include "UnitListas.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
   if (l1 == NULL)
      return l2;
   if (l2 == NULL)

      return l1;

   if (l1->val <= l2->val)
   {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
   }
   else
   {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
   }
}

struct ListNode *mergeKLists(ListNode **lists, int listsSize)
{
   if (listsSize == 0)
      return NULL;

   int interval = 1;
   while (interval < listsSize)
   {
      for (int i = 0; i < listsSize - interval; i += interval * 2)
      {
         lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
      }
      interval *= 2;
   }
   return lists[0];
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
   int k = 3; // Número de listas
   int listsSize = k;

   ListNode **lists = new ListNode *[k];

   // Criar as listas ligadas
   lists[0] = new ListNode{1, new ListNode{3, new ListNode{8, NULL}}};
   lists[1] = new ListNode{1, new ListNode{3, new ListNode{6, NULL}}};
   lists[2] = new ListNode{8, new ListNode{9, NULL}};

   // Mesclar as listas
   ListNode *mergedList = mergeKLists(lists, listsSize);

   // Exibir o resultado
   Memo1->Clear();
   AnsiString result = "[";
   while (mergedList != NULL)
   {
      result += IntToStr(mergedList->val);
      mergedList = mergedList->next;
      if (mergedList != NULL)
         result += ",";
   }
   result += "]";

   Memo1->Clear();
   Memo1->Lines->Add("Lista original:");

   Memo1->Lines->Add("[[1,3,8],[1,3,6],[8,9]]");
   Memo1->Lines->Add("        ");
   Memo1->Lines->Add("Lista ordenada:");

   Memo1->Lines->Add(result);

   // Liberar a memória alocada
   for (int i = 0; i < k; i++)
   {
      ListNode *current = lists[i];
      while (current != NULL)
      {
         ListNode *temp = current;
         current = current->next;
         delete temp;
      }
   }
   delete[] lists;
}
//---------------------------------------------------------------------------

