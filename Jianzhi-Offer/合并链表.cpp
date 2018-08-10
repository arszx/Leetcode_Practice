//对两个排序链表进行合并，输出一个链表，注意空链表的问题；
ListNode * Merge(ListNode * pHead1,ListNode * pHead2)
{
  if(pHead1==NULL)
    return pHead2;
  else if(pHead2==NULL)
    return pHead1;
  
  ListNode * pMergedHead=NULL;
  
  if(pHead1->m_nValue<pHead2->m_nValue)
  {
    pMergedHead=pHead1;
    PMergedHead->m_pNext=Merge(pHead1->m_pNext,pHead2);
  }
  else
  {
    pMergedHead=pHead2;
    pMergedHead->m_pNext=Merge(pHead1,pHead2->m_pNext);
  }
  
  return pMergedHead;
}
