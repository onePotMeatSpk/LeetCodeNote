#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<time.h>
#include"��������.h"
#include"���������������г��ֵĴ���.h"
#include"0��n-1��ȱʧ������.h"
#include"��������������ĺ����.h"
#include"���������ֳ��ֵĴ���.h"
#include"��Ϊs����������.h"
#include"��Ϊs��������������.h"
#include"��ת����˳��.h"
#include"����ת�ַ���.h"
#include"�������ڵ����ֵ.h"
#include"���е����ֵ.h"
#include"n��ɸ�ӵĵ���.h"
#include"ԲȦ�����ʣ�µ�����.h"
#include"��Ʊ���������.h"
#include"��1+2+��+n.h"
#include"���üӼ��˳����ӷ�.h"
#include"���ֵ��ȥ��СֵС�ڻ����num������������.h"
#include"����Ӿ���.h"
#include"����������ĳֵ����Ϊ���С���м���ȣ��ұߴ����ʽ.h"
#include"�����е��������.h"

using namespace std;

int main()
{
    vector<int> v1 = { 7,2,4,3 }, v2 = { 5,6,4 };
    ListNode* l1 = createList(v1);
    printList(l1);
    ListNode* l2 = createList(v2);
    printList(l2);

    ListNode* l3 = addTwoNumbers(l1, l2);
    printList(l3);

    return 0;
}

